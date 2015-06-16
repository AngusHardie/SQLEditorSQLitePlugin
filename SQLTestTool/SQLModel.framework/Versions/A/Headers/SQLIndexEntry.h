//
//  SQLIndexEntry.h
//  SQLEditorUniversal2
//
//  Created by Angus W Hardie on 30/04/2008.
//  Copyright 2008 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "SQLObject.h"

@interface SQLIndexEntry : SQLObject {

	id field;
}
- (void) setPrefixSize:(NSString*) size;
- (NSString*) getPrefixSize;

- (id)field;
- (void)setField:(id)value;


@end
