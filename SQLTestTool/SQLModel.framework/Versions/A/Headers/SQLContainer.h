/*
 *  SQLContainer.h
 *  SQLEditor
 *
 *  Created by Angus Hardie on Thu Jul 15 2004.
 *  Copyright (c) 2004 MalcolmHardie Solutions Ltd. All rights reserved.
 *
 */

#import <Cocoa/Cocoa.h>
#import "SQLPoint.h"
#import "SQLObjectPeer.h"
#import "SQLObjectContainer.h"

@class SQLDocumentInfo;
@class SQLObject;
@class SQLIterator;

@class SQLObjectLabelManager;

@class MHSparseMutableArray;

@class SQLSchema;

/**
	SQLContainer is the main container class for documents
 It accepts different types of SQLObject and works in conjunction with SQLSchemaView to display them
**/
EXPORT_SYMBOL_EXTERNAL
@interface SQLContainer :SQLObjectPeer <SQLObjectContainer>
{
    
	NSMutableArray* _objectList;
    
    NSString* _debug;
	
	id _lastObjectAdded;
	
	BOOL _isTempContainer;
    
	BOOL _allowsFieldObjects;
    
	NSString* _uid;
    
    SQLDocumentInfo* _documentInfo;
    
    NSMutableArray* _uidList;
	
	id _document;
	
	SQLObjectLabelManager* _objectLabelManager;
	
	MHSparseMutableArray* zorderArray;
    
    NSArray* importErrors;
}

@property (retain) NSArray* importErrors;

@property (retain) NSMutableArray* schemaList;

- (SQLObjectLabelManager*)objectLabelManager;

- (BOOL)contains:(id)object;
- (void)add:(id)object;
- (void)addWithRenaming:(SQLObject*) object;
- (BOOL)addObjectToContainer:(id) object ;
- (void)remove:(id)object;

- (void)moveElementToPosition:(id)object :(NSInteger) position;


- (id)getModel;


- (NSInteger)count;

- (NSData*) xmlData;
- (NSString*) exportToXML;
- (NSString*) exportToSQL;
- (NSString*) exportToSQLWithDocumentInfo:(SQLDocumentInfo*) documentInfo;
- (NSString*) exportObjectToSQLWithDocumentInfo:(SQLObject*) so  :(SQLDocumentInfo*) documentInfo;


- (id)firstElement;
- (id)lastObjectAdded;

- (void)setIsTempContainer:(BOOL)temp;
- (BOOL)isTempContainer;


- (void)relocateAllToBase:(NSPoint)p;

- (NSPoint)origin;

- (id)getNextObject:(id)object;
- (id)getPreviousObject:(id)object;
- (id)getFirstObject;

- (NSArray*) getObjects;
- (void) setObjects:(NSArray*)newObjectArray;
- (NSArray*)objectList;

- (SQLIterator*) iterator;
- (void)merge:(SQLContainer*)mergeContainer;
- (void) merge:(SQLContainer*) c2 :(BOOL) internalLinks;

- (void)postLoadProcess;
- (void)removeAll;

- (id) getObjectWithUID:(NSString*)uid;
- (BOOL) uidInContainer:(NSString*) uid;
- (void)uidChanged:(id)uid forObject:(id)object;


- (NSString*) getValidNameForObject:(SQLObject*) object :(NSString*) originalName;
- (BOOL) isObjectNamePresent:(NSString*) tableName;

- (void)reorderByForeignKeys;
- (void)reorderByUID;

- (void) setAllowsFieldObject:(BOOL) allowsFieldObjects;
- (BOOL) allowsFieldObjects;

- (NSRect)minimumRectForContainer;

- (void) relocateAll:(NSPoint) p ;

- (id) getObjectByName:(NSString*) newName;
- (id) getObjectByName:(NSString*) name :(BOOL)caseSensitive;
- (id) getObjectByName:(NSString*) name :(BOOL)caseSensitive :(Class)objectClass;
- (id) getObjectByName:(NSString*) objectName :(BOOL)caseSensitive :(Class) objectClass :(BOOL)removeQuotes;
- (id) getObjectByName:(NSString*) objectName :(BOOL)caseSensitive :(Class) objectClass :(BOOL)removeQuotes :(BOOL) ignoreSchema;

- (id) getObjectWithSchema: (NSString*) tableName :(NSString*) schemaName;

- (BOOL) isEmpty ;

- (NSEnumerator*)objectListEnumerator;
- (NSArray*)objectListByZOrder;
- (NSInteger)zorderForObject:(id)object;
- (void)setZorderForObject:(id)object zorder:(NSInteger)position;

- (SQLDocumentInfo *)documentInfo;
- (void)setDocumentInfo:(SQLDocumentInfo *)value;


- (void)containerChanged;

- (void) updateTargetTableLists;

- (NSArray*)objectListSortedByUid;
- (NSArray*)objectListSortedByZOrder;
- (NSArray*)objectListSortedByName;
- (NSArray*)flatObjectList;
- (void)reorderByZOrder;

//schema list support
- (NSArray*)objectsWithSchema:(SQLSchema*)schema;
- (NSArray*)listOfSchema;
- (void)updateSchemaForObject:(SQLObject*)object;

- (void)removeUidForObject:(id)object;
- (void)addUidForObject:(id)object;
@end



