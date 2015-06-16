//
//  SQLExportDialect.h
//  SQLEditorUniversal2
//
//  Created by Angus W Hardie on 30/04/2008.
//  Copyright 2008 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class SQLIndex;
@class SQLDocumentInfo;
@class SQLTable;
@class SQLIndex;
@class SQLField;
@class SQLTableComponent;

@class SQLForeignKey;
@class JDBCExport;
@class SQLObject;

@class SQLConstraint;

@interface SQLExportDialect : NSObject {

}

- (void)configureForExport;

- (NSString*)getName;
- (NSString*)export:(id)object ;

- (void)setDocumentInfo:(SQLDocumentInfo*)d ;
- (NSString*)postLoad:(SQLTable*)table ;
- (NSMutableArray*)postLoadAsVector:(SQLTable*)table ;
- (NSMutableArray*)alterAsVector:(SQLField*)newField :(SQLField*)curField ;
- (NSString*)dropForeignKey:(SQLField*)field ;
- (NSString*)dropColumn:(SQLField*)field ;
- (NSString*)alter:(SQLTable*)table :(SQLTable*)newTable ;
- (NSString*)quoteIdentifier:(NSString*)identifier ;
- (NSString*)addIndex:(SQLIndex*)index ;
- (NSString*)addConstraint:(SQLConstraint*)constraint;

- (NSString*)addColumn:(SQLField*)field ;
- (NSString*)drop:(id)item;

- (NSString*)getInstructionSeparator;
- (NSMutableArray*)quoteAllMembers:(NSMutableArray*)objectList ;
- (NSString*)getCanonicalName:(id)item;
- (NSString*)getNameForIndex:(SQLTable*)table withIndex:(SQLIndex*)index ;
- (NSString*)getNameForIndex:(SQLTable*)table withName:(NSString*)indexName withSuffix:(NSString*)suffix withQuotes:(BOOL)withQuotes;

- (void)setJDBCMetaData:(id)jdbcMetaData ;

- (id)currentExporter;
- (void)setCurrentExporter:(id)value;

- (NSString*)dropSQLField:(SQLField*)index ;
- (NSString*)dropSQLIndex:(SQLIndex*)index ;


- (NSString*)requiredSizeForType:(NSString*)typeString;

- (NSMutableArray*)alterSQLForeignKeyAsVector:(SQLForeignKey*) newForeignKey 
											 :(SQLForeignKey*) existingForeignKey 
											 :(JDBCExport*)exporter;

- (NSMutableArray*)postLoadAsVector:(SQLObject*)object :(SQLObject*)parentObject;

- (NSMutableArray*)alterAsVector:(SQLObject*)object :(SQLObject*)parentObject :(JDBCExport*)exporter;
@end
