//
//  SQLSize.h
//  XMLParserTest
//
//  Created by Angus Hardie on 04/01/2006.
//  Copyright 2006 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SQLValue.h"

@interface SQLSize : SQLValue {
	NSSize _size;
}

+ (id)sizeWithSize:(NSSize)size;
- (void)setSize:(NSSize)size;
- (NSSize)sizeValue;

- (void)setWidth:(double)width;
- (void)setHeight:(double)height;
@end
