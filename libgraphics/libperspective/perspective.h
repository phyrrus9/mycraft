//
//  perspective.h
//  libperspective
//
//  Created by Ethan Laur on 6/6/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "../graphics.h"

#ifndef __libperspective__perspective__
#define __libperspective__perspective__

#include <iostream>

class perspective : public image
{
public:
    void zoomOut(int level);
};

#endif /* defined(__libperspective__perspective__) */
