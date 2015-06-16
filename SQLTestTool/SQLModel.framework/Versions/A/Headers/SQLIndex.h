/*
 *  SQLIndex.h
 *  SQLEditorNV2
 *
 *  Created by Angus Hardie on 29/08/2005.
 *  Copyright 2005 MalcolmHardie Solutions Ltd. All rights reserved.
 *
 */

#import <Cocoa/Cocoa.h>
#import "SQLField.h"
#import "SQLIterator.h"

@class SQLIndexEntry;
@class MHSparseMutableArray;
/**
	Interface for SQLModel.SQLIndex
**/
EXPORT_SYMBOL_EXTERNAL
@interface SQLIndex : SQLTableComponent {
    
	
	MHSparseMutableArray* _fieldNameList;
	
	//NSMutableArray* _indexList;
    
    NSMutableDictionary* _fieldSizeList;
    
    NSMutableArray* _fieldSizeListPreLoad;
	
	NSMutableArray* _indexEntryList;
    
}

- (id)initWithName:(NSString*)indexName;
+ (SQLIndex*)indexWithName:(NSString*)name;
+ (SQLIndex*)index;

- (NSArray*)fieldList;



- (SQLIterator*)indexedListIterator;
- (int)indexListCount;

- (void)setFieldName:(NSString*)name;

- (void)addIndexField:(id)field;
- (void)insertIndexFieldAtPosition:(id)field :(int)position;

- (void)removeIndexField:(id)field;

- (BOOL)indexContainsField:(id)field;


- (void)setIncludesIndexFieldForBoolean:(id) field :(BOOL)include;

- (void)updateIndexFieldList;
- (NSArray*)getIndexList;

- (NSString*)getIndexType;
- (void)setIndexType:(NSString*)type;

- (NSString*) getSizeForIndexEntry:(SQLField*) field;
- (void)setSizeForIndexEntry:(SQLField*) field :(NSString*) size;

//- (NSString*)getUid;
- (NSString*)getLabel;
- (NSMutableArray*)getFieldNameList;
- (NSMutableArray*)getFieldNameListWithPrefixes:(BOOL)addFieldPrefixSize;

- (void) addIndexEntry:(SQLIndexEntry*) entry;

- (NSString*)getIndexTypeString;

- (void)insertFieldName:(NSString*)name :(NSInteger)position;
@end