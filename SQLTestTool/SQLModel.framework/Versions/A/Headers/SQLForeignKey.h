/*
 *  SQLForeignKey.h
 *  SQLEditorXC3b
 *
 *  Created by Angus Hardie on 11/1/2009.
 *  Copyright 2009 MalcolmHardie Solutions Ltd. All rights reserved.
 *
 */

#import <Cocoa/Cocoa.h>
#import "SQLField.h"
#import "SQLIterator.h"
#import "SQLConnectable.h"

@class SQLForeignKeyEntry;
@class SQLTable;
/**
 Interface for SQLModel.SQLForeignKey
 **/
EXPORT_SYMBOL_EXTERNAL
@interface SQLForeignKey : SQLTableComponent <SQLConnectable>
{
	
	SQLTable* _targetTable;
    
    NSMutableArray* _fieldPairList;
    
    int _deleteAction;
    int _updateAction;
    
    int _sourceCardinality;
    int _destinationCardinality;
    
	    SQLField* _fkField;
}

- (NSString*) getLabel;

- (SQLForeignKeyEntry*)getKeyPairAtIndex:(int)index;


- (void)addFieldPair:(SQLField*) source :(SQLField*) target;

- (void)addForeignKeyEntry:(SQLForeignKeyEntry*)entry;
- (void)removeFieldPairAtIndex:(int)index;

- (SQLForeignKeyEntry*)createEntryObject;


- (NSString*) getComparisonString;


- (SQLTable*)getTargetTable;
- (void)setTargetTable:(SQLTable*)targetTable;
- (void)setTargetTableByName:(NSString*) targetTableName;
- (NSString*)getTargetTableName;

- (SQLIterator*)getPossibleSourceFieldIterator;
- (SQLIterator*)getPossibleTargetFieldIterator;

- (int)getKeyPairCount;



- (SQLIterator*)keyPairIterator;

- (NSArray*) getSourceList;
- (NSArray*) getTargetList;

- (void)updateWithChangedModel;

- (void)setDefaultCardinalityForImport;

@end
