//
//  SQLObject.h
//  SQLEditor
//
//  Created by Angus W Hardie on Tue Mar 23 2004.
//  Copyright (c) 2004 MalcolmHardie Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class SQLContainer;
@class SQLObjectLabel;

#import "SQLObjectImportable.h"


@class MHMutableNotifyingPropertyDictionary;

/**
 Interface for SQLModel.SQLObject;
 **/
@interface SQLObject : NSObject <SQLObjectImportable,NSCopying> 
{
    

	MHMutableNotifyingPropertyDictionary* properties;

	id _container;
	NSPoint _location;
	NSString* _name;
	NSSize _size;
	
	SQLObjectLabel* label;
	
	id undoManager;
}


- (NSString*)exportToXML;
- (NSString*)exportToSQL;
- (NSString*)getName;
- (id)name;
- (void)setName:(NSString*)name ;
- (NSSize)getSize;
- (void)setSize:(NSSize)size ;
- (NSPoint)getLocation;
- (void)setLocation:(NSPoint)loc ;
- (void)postLoadProcess;

- (void)setContainer:(id)container ;
- (id)getContainer;
- (id)container;
- (id)topLevelContainer;

- (NSString*)getUid;
- (BOOL)setUid:(NSString*) uid;
- (NSString*) uid;

- (void)createNewUid;
- (void) checkUid:(SQLContainer*) c;
- (void)updateLinksWithNewUid;
- (void)resetUid;

- (void)setProperties:(NSDictionary*)newProperties;
- (id)getProperties;
- (id)properties;
- (void)setProperty:(NSString*)key :(NSString*)value;
- (BOOL)hasProperty:(NSString*)key;
- (BOOL)getPropertyAsBoolean:(NSString*)key;
- (NSString*)getProperty:(NSString*)key;
- (void)setPropertyAsBoolean:(NSString*)key :(BOOL)value;
- (void)removeProperty:(NSString*)key;

- (void)setLabel:(SQLObjectLabel*)label;
- (SQLObjectLabel*)label;

- (void)setLabelIndex:(NSUInteger)index;
- (NSUInteger)labelIndex;

- (id)quoteForXML:(id)value;



- (id)exportPropertiesToXML;






- (void)setComment:(id)comment;
- (id)getComment;


- (NSXMLElement*)exportToXMLNode;
- (id)exportPropertiesToXMLNode:(NSXMLElement*)exportNode;
- (NSXMLElement*)exportLocationToXMLNode:(NSXMLElement*)exportNode;


- (NSColor*)defaultLabelColor;

- (NSUndoManager*)undoManager;
- (void)setUndoManager:(id)newUndoManager;

- (NSPoint)location;
- (NSSize) size;
@end
