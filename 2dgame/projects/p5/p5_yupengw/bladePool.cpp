#include "bladePool.h"
#include "collisionStrategy.h"
#include "homeSprite.h"
#include "player.h"

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
    for( Rival* d : actives ) {
      delete d;
    }
  }
}

void BladePool::push( Rival* d ) {
  inPools.push_back(d);
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

void BladePool::active(){
 if( !inPools.empty() && std::rand()%2 == 0) {
   Rival* d = inPools.back();
   actives.push_back(d);
   inPools.pop_back();
 }
}

void BladePool::collideWith( const Drawable* p, const HomeSprite* home ) {
  player = static_cast<Player*>(p);
  bool deleted = false;
  
  auto it = actives.begin();
  while ( it != actives.end() ) {
    deleted = false;
    Rival* doa = static_cast<Rival*>(*it);
    // Check if player is collided with rival.
    // if ( strategies[0]->execute(*player, **it) ) {
    if ( strategy->execute(*player, **it) ) {
      // If the rival is attacking, check if the player defends or not.
      if( doa->isHit()) {
        if( player->getMode() == 4 )
          player->setVelocityX(-200);
        // else
        //   player->jumping();
      }
      // If the player is attacking, set the rival to fall.
      if( player->isHit() && doa->getMode() < 2 ) {
        doa->falling();
      }
    }

    // else if ( strategies[1]->execute(*home, **it) ) {
    else if ( strategy->execute(*home, **it) ) {
      if( doa->isHit() ) {
        home->shake();
      }
    }
    // Check the deads
    if( doa->getMode() == 3 ) {
      player->detach(doa);
      delete doa;
      it = sprites.erase(it);
      deleted = true;
    }
    if( !deleted ) ++it;
  }
}
