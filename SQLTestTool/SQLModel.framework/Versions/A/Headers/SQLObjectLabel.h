//
//  SQLObjectLabel.h
//  SQLEditorUniversal4e
//
//  Created by Angus Hardie on 11/08/2009.
//  Copyright 2009 MalcolmHardie Solutions Limited. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SQLObject.h"
/**
 Represents a label assigned to an object
 **/
@interface SQLObjectLabel : SQLObject <SQLObjectImportable>{
	NSColor* color;
	NSString* name;
	BOOL isHidden;
	BOOL isExpanded;
	BOOL isDefault;
}
@property (assign) BOOL isDefault;
@property (assign,getter=isExpanded,setter=setExpanded:) BOOL isExpanded;
@property (assign,getter=isHidden,setter=setHidden:) BOOL isHidden;

- (id)initWithName:(NSString*)name color:(NSColor*)color;
- (void)setColor:(NSColor*)newColor;
- (NSColor*)color;
- (void)setName:(NSString*)newName;
- (NSString*)name;

@end
