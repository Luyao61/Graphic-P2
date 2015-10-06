//
//  House.hpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Luyao Zhou on 10/6/15.
//  Copyright © 2015 RexWest. All rights reserved.
//

#ifndef House_hpp
#define House_hpp

#include <stdio.h>
#include "Drawable.h"



class House : public Drawable
{
    
public:
    House(void);
    virtual ~House(void);
    
    virtual void draw(DrawData&);
};
#endif /* House_hpp */

