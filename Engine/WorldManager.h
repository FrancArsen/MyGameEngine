//
//  WorldManager.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/29/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Manager.h"
#include "ObjectList.h"
#include "Vector.h"
#include "Box.h"

// Two-letter acronym for easier access to manager.
#define WM df::WorldManager::getInstance()

namespace df {

const int MAX_ALTITUDE = 4;

class WorldManager : public Manager {
    
private:
    WorldManager();                 // Private since a singleton.
    WorldManager (WorldManager const&);  // Don't allow copy.
    void operator=(WorldManager const&); // Don't allow assignment.
    ObjectList m_updates;		  // All Objects in game world.
    ObjectList m_deletions;         // List of all Objects to delete.
    Box m_boundary;
    Box m_view;
    Object *m_p_view_following;     // Object view is following.

    
public:
    // Get the one and only instance of the WorldManager.
    static WorldManager &getInstance();
    
    // Startup game world (initialize everything to empty).
    // Return 0.
    int startUp();
    
    // Shutdown game world (delete all game world Objects).
    void shutDown();
    
    // Insert Object into world.
    // Return 0 if ok, else -1.
    int insertObject(Object *p_o);
    
    // Remove Object from world.
    // Return 0 if ok, else -1.
    int removeObject(Object *p_o);
    
    // Return list of all Objects in world.
    ObjectList getAllObjects() const;
    
    // Return list of all Objects in world matching type
    ObjectList objectsOfType(std::string type) const;
    
    // Indicate Object is to be deleted at end of current game loop.
    // Return 0 if ok, else -1.
    int markForDelete(Object *p_o);
    
    // Update world.
    // Delete Objects marked for deletion.
    void update();
    
    //draw all objects
    void draw();
    
    // Move Object.
    // If collision with solid, send collision events.
    // If no collision with solid, move ok else don't move Object.
    // If Object is Spectral, move ok.
    // If move ok, adjust view if following this Object.
    // If moved from inside world boundary to outside, generate EventOut.
    // Return 0 if move ok, else -1 if collision with solid.
    int moveObject(Object *p_o, Vector where);

    // Return list of Objects collided with at position 'where'.
    // Collisions only with solid Objects.
    // Does not consider if p_o is solid or not.
    ObjectList getCollisions(const Object *p_o, Vector where) const;
    
    // Get game world boundary.
    Box getBoundary() const;

    // Set game world boundary.
    void setBoundary(Box new_boundary);

    // Get player view of game world.
    Box getView() const;

    // Set player view of game world.
    void setView(Box new_view);
    
    // Set view to center screen on Object.
    // Set to NULL to stop following.
    // If Object not legit, return -1 else return 0.
    int setViewFollowing(Object *p_new_view_following);

    // Get Object view is following (NULL if none).
    Object *getViewFollowing() const;

    // Set view to center screen on position view_pos.
    // View edge will not go beyond world boundary.
    void setViewPosition(Vector new_view_pos);

};

}
#endif /* __WORLD_MANAGER_H__ */
