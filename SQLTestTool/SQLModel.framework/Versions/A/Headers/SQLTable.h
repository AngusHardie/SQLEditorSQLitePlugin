//
//  SQLField.h
//  SQLParser
//
//  Created by Angus W Hardie on Sun Nov 02 2003.
//  Copyright (c) 2003 Malcolmhardie.com. All rights reserved.
//
#import <Cocoa/Cocoa.h>
#import "SQLField.h"

#import "SQLIterator.h"
#import "SQLObjectPeer.h"
#import "SQLDocumentInfo.h"
#import "SQLObject.h"
#import "SQLObjectContainer.h"

@class SQLIndex;
/**
 Interface for SQLModel.SQLTable
 **/
EXPORT_SYMBOL_EXTERNAL
@interface SQLTable : SQLObjectPeer <SQLObjectContainer>{
	
	
	
    
    NSMutableArray* _fields;
	
    NSString* _tableType;
	NSString* _schemaName;
	int _sortPosition;
    NSString* _otherOptions;
	
    NSMutableArray* _targetTableForFKList;
    
    NSString* indexPrefix;
    
    NSMutableArray* primaryKeyObjectList;
	NSMutableArray* primaryKeyNameList;
    
    NSMutableArray* observingForeignKeys;
}

@property (copy) NSString* indexPrefix;
@property (copy) NSString* primaryKeyConstraintName;

+ (SQLTable*)tableWithName:(NSString*)name;
+ (SQLTable*)table;

- (id)init;
- (id) initWithName:(NSString*)name tableType:(NSString*)type schemaName:(NSString*)schemaName;
- (id) initWithName:(NSString*)name tableType:(NSString*)tableType;
- (id) initWithName:(NSString*)name;




- (void)createNewUid;
- (void)updateLinksWithNewUid;
- (void)setSortPosition:(int)pos ;
- (int)getSortPosition;
+ (void)resetPosition;
//- (BOOL)getHasViewPeer;
//- (void)setHasViewPeer:(BOOL)hasViewPeer ;
//- (id)clone;
- (NSString*)getClassType;
//- (void)setContainer:(SQLObject*)container ;
//- (SQLObject*)getContainer;
- (void)postLoadProcess;
- (int)getFieldCount;
- (int)fieldCount;
- (int)columnCount;
- (NSArray*)foreignKeyFieldsInTable;
- (NSArray*)indexObjectsInTable;
- (BOOL)isIndexSoleIndexOnColumn:(SQLIndex*)index column:(SQLField*)field;





- (void)add:(SQLTableComponent*)object ;

- (void)addComponent:(SQLTableComponent*)field ;
//- (void)addComponent:(SQLField*)field ;
- (void)addWithRenaming:(SQLTableComponent*)field ;
- (void)addWithRenaming:(SQLTableComponent *)field didRename:(BOOL*)didRename;


- (int)getFieldPosition:(SQLTableComponent*)curField ;
- (void)reorder:(SQLTableComponent*)newField :(int)position ;


- (NSString*)getValidNameForObject:(SQLTableComponent*)field :(NSString*)originalName ;
- (NSString*)getValidName:(NSString*)originalName ;
- (BOOL)isObjectNamePresent:(NSString*)name ;
- (BOOL)isFieldNamePresent:(NSString*)name ;
- (BOOL)isFieldNamePresent:(NSString*)name :(BOOL)ignoreCase ;
- (BOOL)isFieldNamePresent:(NSString*)name :(BOOL)ignoreCase :(Class)objectClass;


- (NSMutableArray*)getFields;
- (NSMutableArray*) fields;
- (void)setFields:(NSMutableArray*)fields ;

- (SQLTableComponent*)getNextObject:(SQLTableComponent*)object ;
- (SQLTableComponent*)getPreviousObject:(SQLTableComponent*)object ;
- (SQLField*)getColumn:(int)number ;
- (SQLTableComponent*)getField:(int)position ;


- (BOOL)contains:(SQLTableComponent*)field ;
- (void)remove:(SQLTableComponent*)field ;

- (NSString*)fullyQualifiedName;
- (NSString*)displayName;
- (void)setDisplayName:(NSString*)name;

- (NSString*)getBaseName;
- (void)setBaseName:(NSString*)baseName ;
- (NSString*)getName;
- (void)setName:(NSString*)name ;
- (NSString*)schema;
- (NSString*)getSchemaName;
- (void)setSchemaName:(NSString*)schemaName ;
- (NSString*)getSchema;
- (void)setSchema:(NSString*)schemaName ;
- (NSString*)getTableType;
- (void)setTableType:(NSString*)tableType ;
- (void)setType:(NSString*)type ;
- (NSString*)getType;
- (NSString*)getComment;
- (void)setComment:(NSString*)comment ;
- (void)setOtherOptions:(NSString*)otherOptions ;
- (NSString*)getOtherOptions;
- (SQLIterator*)listIterator;
- (SQLIterator*)iterator;

//- (NSSize)getSize;
//- (void)setSize:(NSSize)size ;
//- (NSPoint)getLocation;
//- (void)setLocation:(NSPoint)location ;
- (NSString*)exportToXMLWithWrapper;
- (NSString*)toString;
//- (NSString*)exportToXML;
- (NSString*)getNameForSQL;
- (NSString*)exportToSQL;
- (NSString*)exportToSQL:(BOOL)showReferencesInline documentInfo:(SQLDocumentInfo*)documentInfo ;
- (NSString*)exportSQLForeignKey;
- (SQLTableComponent*)getNextField:(SQLTableComponent*)curField ;
- (SQLTableComponent*)getPreviousField:(SQLTableComponent*)curField ;
- (NSArray*)primaryKeyList;
- (NSArray*)primaryKeyObjectList;



- (SQLTableComponent*) getFieldByName:(NSString*) namel;
- (SQLTableComponent*) getFieldByTypeAndName:(Class) type :(NSString*) name;
- (SQLTableComponent*) getFieldByTypeAndName:(Class) type :(NSString*) name :(BOOL) ignoreCase;
- (SQLTableComponent*)getObjectByName:(NSString*)name ;

- (SQLTableComponent*)getFieldByUID:(NSString*)uid ;



- (void) addTableToTargetList:(SQLTable*) table;
- (void) clearTargetTableList;
- (NSArray*)getTargetTableForFKList;


- (NSString*)getFieldNameListString;

-(BOOL)validateDisplayName:(id *)ioValue error:(NSError **)outError;

- (void)updatePrimaryKeyList;
//- (void)willUpdatePrimaryKey:(id)sender;
//- (void)didUpdatePrimaryKey:(id)field;


- (void)stopObservingTableForForeignKey:(SQLField*)observingField;
- (void)observeTableForForeignKey:(SQLField*)observingField;

- (NSString*)primaryKeyConstraintName;

- (BOOL)fieldIsIndexed:(SQLField*)field;
@end
