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
  active();

  for( Rival* d : actives ) {
    d->update(ticks);
  }
  
}

void BladePool::active(){
  if( !inPools.empty() && std::rand()%51 == 7 ) {
    static_cast<Rival*>(inPools.back())->init();
    actives.push_back(inPools.back());
    inPools.pop_back();
  }
}

void BladePool::collideWith( Drawable* p, HomeSprite* home ) {
  Player* player = static_cast<Player*>(p);
  bool deleted = false;
  
  auto it = actives.begin();
  while ( it != actives.end() ) {
    deleted = false;
    // Check if player is collided with rival.
    // if ( strategies[0]->execute(*player, **it) ) {
    if ( strategy->execute(*player, **it) ) {
      // If the rival is attacking, check if the player defends or not.
      if( (*it)->isHit()) {
        if( player->getMode() == 4 )
          player->setVelocityX(-200);
        // else
        //   player->jumping();
      }
      // If the player is attacking, set the rival to fall.
      if( player->isHit() && (*it)->getMode() < 2 ) {
        (*it)->falling();
      }
    }

    // else if ( strategies[1]->execute(*home, **it) ) {
    else if ( strategy->execute(*home, **it) ) {
      if( (*it)->isHit() ) {
        home->shake();
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
