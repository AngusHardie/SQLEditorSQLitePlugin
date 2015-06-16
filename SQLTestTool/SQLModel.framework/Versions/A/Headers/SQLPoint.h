//
//  SQLPoint.h
//  XMLParserTest
//
//  Created by Angus Hardie on 04/01/2006.
//  Copyright 2006 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SQLValue.h"


@interface SQLPoint : SQLValue {
	NSPoint _point;
}

+ (id)pointWithPoint:(NSPoint)point;
- (void)setPoint:(NSPoint)point;
- (NSPoint)pointValue;

- (void)setX:(double)x;
- (void)setY:(double)y;

@end
