//
//  GenericSQLExporter.h
//  SQLEditorUniversal
//
//  Created by Angus Hardie on 11/01/2007.
//  Copyright 2007 MalcolmHardie Solutions Limited and Angus W Hardie. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@class JDBCExport;
@class SQLDatabaseMetaData;
@class SQLContainer;
@class SQLTable;
@class SQLField;
@class SQLIndex;
@class SQLComment;
@class SQLDocumentInfo;
@class SQLObject;
@class SQLConstraint;
@class SQLForeignKey;

#import "DialectManager.h"

#import "SQLExportDialect.h"


typedef enum {
	SQLExporterUpperCase = 0,
	SQLExporterLowerCase = 1,
	SQLExporterMixedCase = 2,
} SQLExporterTypeDisplayStyle;
EXPORT_SYMBOL_EXTERNAL
@interface GenericSQLExporter : SQLExportDialect {
	id _currentExporter;
	
    id _jdbcMetaData;
    
	SQLDocumentInfo* _documentInfo;
	
	BOOL _isJDBCExporter;
	
	BOOL _useQuotedIdentifier;
    
    BOOL _shouldPrefixIndexNames;
	
    BOOL _autoQuoteIdentifiersWithWhitespace;
    
	int indentSize;
    
    NSMutableDictionary* cache;
}


@property (assign) int indentSize;
@property (assign) BOOL isJDBCExporter;

@property (assign) BOOL shouldPrefixIndexNames;

+ (id)exporter;

- (id)currentExporter;
- (void)setCurrentExporter:(id)value;
- (BOOL)shouldExportIndex:(SQLIndex*)fkIndex;


- (NSString*)instructionSeparator;

- (NSString*)getName;
- (void)setJDBCMetaData:(SQLDatabaseMetaData*)jdbcMetaData ;
- (NSString*)getInstructionSeparator;
- (BOOL)shouldIncludeTitleHeader;
- (BOOL)shouldPrefixIndexNames;
- (NSString*)exportSQLContainer:(SQLContainer*)c ;
- (NSString*)dropTableInstruction:(SQLTable*)table ;
- (NSString*)dropSQLTable:(SQLTable*)table ;


- (NSString*)getCanonicalName:(SQLObject*)index ;


- (NSString*)getCanonicalNameWithLinkString:(SQLTable*)table :(NSString*)linkString ;
- (NSString*)getNameForIndex:(SQLTable*)table withIndex:(SQLIndex*)index ;
- (NSString*)getNameForIndex:(SQLTable*)table withName:(NSString*)indexName ;

- (NSString*)getNameForIndex:(SQLTable*)table withName:(NSString*)indexName withSuffix:(NSString*)suffix;
- (NSString*)getNameForIndex:(SQLTable*)table withName:(NSString*)indexName withSuffix:(NSString*)suffix withQuotes:(BOOL)withQuotes;


- (NSString*)quoteComment:(NSString*)comment ;
- (NSString*)fieldBlock:(SQLTable*)table ;
- (NSString*)primaryKeyBlock:(SQLTable*)table ;

- (NSString*)exportSQLTable:(SQLTable*)table ;

- (NSString*)fieldType:(SQLField*)field ;

- (NSString*)exportSQLIndex:(SQLIndex*)index ;
- (NSString*)exportSQLConstraint:(SQLConstraint*)index ;


- (NSString*)addColumn:(SQLField*)field ;
- (NSString*)exportSQLField:(SQLField*)field ;
- (NSString*)postLoadSQLField:(SQLField*)field :(SQLTable*)table;

- (NSString*)prologueSQLContainer:(SQLContainer*)c ;

- (NSString*)postLoadSQLContainer:(SQLContainer*)c ;
- (NSMutableArray*)postLoadAsVectorSQLContainer:(SQLContainer*)c ;

- (NSString*)postLoadSQLTable:(SQLTable*)table ;

- (NSMutableArray*)postLoadAsVectorSQLTable:(SQLTable*)table ;

- (NSMutableArray*)postLoadAsVectorSQLTableComponent:(SQLTableComponent*)comp :(SQLTable*)table ;

- (NSMutableArray*)postLoadAsVectorSQLField:(SQLField*)field :(SQLTable*)table ;

- (NSMutableArray*)postLoadAsVectorSQLIndex:(SQLIndex*)index :(SQLTable*)table ;

- (NSString*)postLoadSQLTableComponent:(SQLTableComponent*)field :(SQLTable*)table ;
- (NSString*)createFieldIndexOnField:(SQLField*)field table:(SQLTable*)table ;

- (NSString*)addIndex:(SQLIndex*)index ;
- (NSString*)addIndex:(SQLIndex*)index :(SQLTable*)table;
- (NSString*)addField:(SQLTable*)table :(SQLField*)field ;
- (NSString*)createForeignKey:(SQLField*)field asExternalInstruction:(BOOL)asExternalInstruction isInstructionComparison:(BOOL)isInstructionComparison;

- (NSString*)exportSQLComment:(SQLComment*)c ;

- (BOOL)shouldQuoteDefaultFieldValue:(NSString*)value :(SQLField*)field ;
- (NSString*)quoteDefaultValue:(NSString*)value :(SQLField*)field ;
- (NSString*)addQuotes:(NSString*)value ;
- (NSString*)addDefaultQuotes:(NSString*)value ;
- (NSString*)quoteForSQL:(NSString*)exportName ;

- (NSString*)quoteForSQL:(NSString*)exportName :(BOOL)force ;
- (void)setUseQuotedIdentifier:(BOOL)useQuotedIdentifier ;
- (NSString*)getQuoteIdentifierString;
- (NSString*)getQuoteDefaultString;

- (NSString*) getStartingQuoteIdentifierString;
- (NSString*) getEndingQuoteIdentifierString;

- (BOOL)useQuotedIdentifier;
- (NSMutableArray*)quoteAllMembers:(NSArray*)objectList ;

- (NSString*)quoteIdentifier:(NSString*)objectName ;
- (NSString*)escapeQuoteCharacter:(NSString*) input;

- (void)setDocumentInfo:(SQLDocumentInfo*)d ;
- (SQLDocumentInfo*)documentInfo;

- (NSString*)alterPrimaryKey:(SQLField*)newField :(SQLField*)curField ;
- (NSString*)alterType:(SQLField*)newField :(SQLField*)curField ;
- (NSMutableArray*)alterSQLFieldAsVector:(SQLField*)newField :(SQLField*)curField :(JDBCExport*)exporter;
- (NSMutableArray*)alterSQLTableAsVector:(SQLTable*)newTable :(SQLTable*)curTable :(JDBCExport*)exporter;


- (NSMutableArray*)alterAsVector:(SQLObject*)object :(SQLObject*)parentObject :(JDBCExport*)exporter;

- (NSString*)alter:(SQLTable*)table :(SQLTable*)newTable ;
- (int)foreignKeyMatches:(SQLField*)newField :(SQLField*)curField ;
- (NSMutableArray*)alterForeignKey:(SQLField*)newField :(SQLField*)curField ;

- (NSMutableArray*)alterSQLForeignKeyAsVector:(SQLForeignKey*) newForeignKey 
											 :(SQLForeignKey*) existingForeignKey 
											 :(JDBCExport*)exporter;


- (NSString*)alterSQLIndex:(SQLIndex*) newIndex :(SQLIndex*) index;
- (NSString*)alterSQLConstraint:(SQLConstraint*) newIndex :(SQLConstraint*) index;

- (NSString*)dropForeignKey:(SQLField*)dbField ;
- (NSString*)dropSQLForeignKey:(SQLForeignKey*) dbForeignKey;
- (NSString*)dropSQLField:(SQLField*)field ;
- (NSString*)dropColumn:(SQLField*)field ;

- (NSString*)dropSQLIndex:(SQLIndex*)index ;

- (BOOL)fieldTypeAllowsTimeZone:(SQLField*)field;


- (NSString*)createIndexStatement:(SQLField*) field indexName:(NSString*) indexName;

- (BOOL)isStringType:(NSString*)type ;

//
// MARK: -
// MARK: Keywords
// MARK: -
//

- (NSString*)autoIncrementKeyword;
- (NSString*)getIndexKeyword:(SQLIndex*) index;


//
// MARK: -
// MARK: Index Helper Methods
// MARK: -
//

- (NSString*) indexSizeStringForField:(SQLField*) f :(SQLIndex*) anIndex;



//
// MARK: -
// MARK: generics
// MARK: -
//

- (id)genericFunction:(NSString*)functionName forObject:(SQLObject*)object;
- (id)genericFunction:(NSString*)functionName forObject:(SQLObject*)object defaultReturnValue:(id)returnValue;

- (NSString*)prologue:(SQLObject*)c;
- (NSString*)export:(SQLObject*)object;
- (NSString*)drop:(SQLObject*)object;
- (NSString*)postLoad:(SQLObject*)object;
- (NSMutableArray*)postLoadAsVector:(SQLObject*)object;


- (NSMutableArray*)postLoadAsVector:(SQLObject*)object :(SQLObject*)parentObject;


- (NSString*) getForeignKeyExport:(SQLField*) field 
								 table:(SQLTable*) table 
								 localFieldList:(NSArray*) localFieldList 
								 referencesTable:(SQLTable*) referencesTable 
								 referencesFieldList:(NSArray*) referenceFieldList 
								 asExternalInstruction:(BOOL)asExternalInstruction
								 options:(NSDictionary*)properties;


- (void) addTablesLinkedToTable:(SQLTable*) table :(NSMutableArray*) v :(NSMutableArray*) seenList;
- (void) addTablesLinkedToTable:(SQLTable*) table :(NSMutableArray*) v;


- (NSMutableArray*)postLoadAlterSQLFieldAsVector:(SQLField*) newField :(SQLField*) curField;
- (NSMutableArray*)postLoadAlterAsVector:(SQLObject*) a :(SQLObject*) b;
- (NSMutableArray*)postLoadAlterSQLTableAsVector:(SQLTable*) table :(SQLTable*) curTable;

- (NSString*) getDeleteActionStringForCode:(int) deleteActionCode;
- (NSString*) onDeleteAction:(SQLField*) field;

- (NSString*) getUpdateActionStringForCode:(int) updateActionCode;
- (NSString*) onUpdateAction:(SQLField*) field;


- (BOOL) isJDBCExporter;

- (BOOL) supportsIfNotExists;
- (BOOL) supportsIfNotExistsSQLIndex;
- (BOOL)supportsInlineAutoIncrement;

- (NSString*) getSQLForForeignKeyField:(SQLForeignKey*) foreignKeyObject :(BOOL) asExternalInstruction;


- (SQLExporterTypeDisplayStyle)requiredCaseForTypes;
- (BOOL)supportsIndexPrefixSize;
- (NSString*) getIndexNameForFieldIndexed:(SQLField*) field;

- (BOOL)supportsIndexPostLoad;
- (NSString *) createIndexIfNotDuplicate: (SQLTable *) table index: (SQLIndex *) index;

- (NSString*) alterUniqueConstraint:(SQLField*)docField dbField:(SQLField*)dbField;
- (NSMutableArray*)alterIndexedProperty:(SQLField*) newField curField:(SQLField*) curField;


- (BOOL)shouldPrefixFieldLevelIndexNames;
- (BOOL) canDropIndexedProperty: (SQLField *) curField newField: (SQLField *) newField;


- (NSString*)indent;

- (BOOL)canExportObject:(SQLObject*)object;
- (BOOL)canLinkToObject:(SQLObject*)object;

- (void)configureForExport;

- (NSMutableArray*)indexCacheForTable:(SQLTable*)table;
- (void)clearIndexCache;

- (BOOL)quoteReservedWord:(NSString*)objectName;
@end
