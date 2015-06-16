/*
 *  SQLModelController.h
 *  SQLEditor
 *
 *  Created by Angus W Hardie on Wed Sept 15th 2004
 *  Copyright (c) 2004 MalcolmHardie Software. All rights reserved.
 *
 */
#import <Cocoa/Cocoa.h>
/**
	Interface for a basic iterator
**/
@interface SQLIterator : NSObject
{
    id _objectArray;
	int _position;
    int _count;
}

- (BOOL) hasNext;
- (id) next;
+ (id) iteratorForArray:(NSArray*)array;
@end