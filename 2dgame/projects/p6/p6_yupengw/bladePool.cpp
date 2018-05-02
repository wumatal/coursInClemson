#include "bladePool.h"
#include "homeSprite.h"
#include "player.h"
#include "rival.h"

BladePool& BladePool::getInstance() {
  static BladePool instance;
  return instance;
}

void BladePool::deleteAll() {
  if( !actives.empty() ) {
    for( Rival* d : actives ) {
      delete d;
    }
  }
  if( !inPools.empty() ) {
    for( Rival* d : inPools ) {
      delete d;
    }
  }
}

void BladePool::push( Drawable* d ) {
  inPools.push_back(static_cast<Rival*>(d));
}

void BladePool::draw() {
  for( Rival* d : actives ) {
    d->draw();
  }
}

void BladePool::update( Uint32 ticks ) {
  for( Rival* d : actives ) {
    d->update(ticks);
  }
}

void BladePool::active( ){
  if( std::rand() % 51 == 7 ) {
    static_cast<Rival*>(inPools.back())->init();
    actives.push_back(inPools.back());
    inPools.pop_back();
  }
}

void BladePool::active( Player* player, HomeSprite* home ){
  // if( !inPools.empty() && (inPools.size() + actives.size()) > 10 ) {
  if( !inPools.empty() ) {
    active();
  }
  // else {
  else if ((inPools.size() + actives.size())<1) {
    Vector2f pos = player->getPosition();
    int w = player->getScaledWidth();
    int h = player->getScaledHeight();

    Vector2f bpos = home->getPosition();
    int bw = home->getScaledWidth();
    int bh = home->getScaledHeight();

    Rival* d = new Rival("Blade", pos, bpos, w, h, bw, bh);
    push( d );
    player->attach( d );
  }
}


void BladePool::collideWith( Player* player, HomeSprite* home ) {
  // Player* player = static_cast<Player*>(p);
  bool deleted = false;

  auto it = actives.begin();
  while ( it != actives.end() ) {
    deleted = false;
    // Check if player is collided with rival.
    if ( strategy->execute(*(player->getPlayer()), **it) ) {
      // If the rival is attacking, check if the player defends or not.
      if( (*it)->isHit()) {
        if( player->getMode() == 4 )
          player->setVelocityX(-500);
        else if( player->hurtable() ) {
          player->hurting();
          if( player->getPlayer()->subtractHealth((*it)->getAttack()) )
            player->explode();
        }
      }
      // If the player is attacking, set the rival to fall.
      if( player->isHit() && (*it)->getMode() < 2 ) {
        if( (*it)->subtractHealth(player->getPlayer()->getAttack()) )
          (*it)->falling();
      }
    }

    // else if ( strategies[1]->execute(*home, **it) ) {
    else if ( strategy->execute(*home, **it) ) {
      if( (*it)->isHit() ) {
        if( home->subtractHealth((*it)->getAttack()) ) {
          home->explode();
          // lose!
        }
        else {
          home->shake();
        }
      }
    }
    // Check the deads
    if( (*it)->getMode() == 3 ) {
      // player->detach((*it));
      // delete (*it);
      inPools.push_back(*it);
      it = actives.erase(it);
      deleted = true;
    }
    if( !deleted ) ++it;
  }
}
