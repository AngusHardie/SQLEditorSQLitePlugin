//
//  MHStack.h
//  XMLParserTest
//
//  Created by Angus Hardie on 07/06/2005.
//  Copyright 2005 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface MHStack : NSObject {
	NSMutableArray* stackArray;
}

- (id)init;
- (void)dealloc;

- (void)push:(id)object;
- (id)peek;
- (id)pop;
- (void)removeAll;
@end

