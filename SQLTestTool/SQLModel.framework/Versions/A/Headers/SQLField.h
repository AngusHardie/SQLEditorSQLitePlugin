//
//  SQLField.h
//  SQLParser
//
//  Created by Angus W Hardie on Sun Nov 02 2003.
//  Copyright (c) 2003 Malcolmhardie.com. All rights reserved.
//
#import <Cocoa/Cocoa.h>
#import "SQLObjectPeer.h"
#import "SQLTableComponent.h"

#import "SQLDocumentInfo.h"
#import "SQLConnectable.h"


#define DELETE_ACTION_NONE 0
#define DELETE_ACTION_CASCADE 1

#define DELETE_NONE   0 
#define DELETE_CASCADE   1 
#define DELETE_RESTRICT  2
#define DELETE_SET_NULL 3
#define DELETE_NO_ACTION  4
#define DELETE_SET_DEFAULT  5


#define UPDATE_NONE   0 
#define UPDATE_CASCADE   1 
#define UPDATE_RESTRICT  2
#define UPDATE_SET_NULL 3
#define UPDATE_NO_ACTION  4
#define UPDATE_SET_DEFAULT  5

#define ONE  0 
#define ONE_OR_MORE  1 
#define ZERO_PLUS  2 
#define ZERO_OR_ONE  3 
#define MANY  4 


#define FK_COMPOUND_ADDITIONAL 3
#define FK_COMPOUND 2 
#define FK_SIMPLE 1 
#define FK_NONE 0 

@class SQLTable;

EXPORT_SYMBOL_EXTERNAL
@interface SQLField : SQLTableComponent <SQLConnectable>{
    
	
	
	
    
    NSString* _type;
    NSString* _typeSize;
    
    BOOL _primaryKey;
     
    int _deleteAction;
	int _updateAction;
	
    int _sourceCardinality;
    int _destinationCardinality;
    
    NSString* _referencesField;
    NSString* _referencesTable;
    


    SQLField* _fkField;
    
    SQLField* _sourceForeignKey;
    
    BOOL _compoundForeignKey;
    
	NSMutableArray* _dependentFieldList;

    
    NSMutableArray* _indexList;
    
    
    NSString* _referencesTableUID;
    NSString* _referencesFieldUID;
	
    id observingFkTable;
	
	
}

@property (retain) id observingFkTable;

+ (SQLField*)fieldWithName:(NSString*)name type:(NSString*)type;
+ (SQLField*)field;

- (id)initWithName:(NSString*)newName type:(NSString*)newType;

- (void)setType:(NSString*)type;
- (NSString*)getType;
- (NSString*) getDataType;
- (NSString*) getDataTypeSize;
- (void)setDataType:(NSString*)newType;

- (BOOL) hasTypeSize;

- (NSString *)typeSize;
- (void)setTypeSize:(NSString *)value;

-(NSString*) getFullTypeString;



- (void)setFkField:(SQLField*)field;

- (NSString*)getLabel;

- (NSString*)getClassType;

- (NSString*)exportToSQL;
//- (NSString*)exportToXML;

- (SQLField*) getFkField;
- (SQLField*)fkField;

- (int) getSourceCardinality;
- (void) setSourceCardinality:(SQLCardinalityType) cardinality;
- (int) getDestinationCardinality;
- (void) setDestinationCardinality:(SQLCardinalityType) cardinality;
- (id) getParent;
- (SQLTable*)parentTable;

- (NSString*)getDefaultValue;
- (NSString *)defaultValue;
- (BOOL)getPrimaryKey;
- (BOOL)getAutoIncrement;



- (void)setDefaultValue:(NSString*)defaultValueSetting;
- (void)setPrimaryKey:(BOOL)primaryKeySetting;

- (void)setAutoIncrement:(BOOL)autoIncrementSetting;



- (NSString*) getReferenceInformationString;
- (NSString*) getReferences;
- (NSString*) getReferencesString;
- (NSString*) getReferenceName;

- (int)foreignKeyMode;

- (BOOL)getNotNull;
- (void)setNotNull:(BOOL)notNull;

- (void)setUnique:(BOOL)value;
- (BOOL)isUnique;

- (BOOL)getFkTypeMismatch;
- (NSString*)getOriginalType;

- (BOOL)isForcedUnsigned;
- (BOOL) getForcedUnsigned;

- (void)setReferenceLinkName:(NSString*)referenceLinkName;
- (NSString*)getReferenceLinkName;




- (id) getReferencesField;
- (void)setReferencesFieldUID:(NSString *)newReferencesFieldUID;
- (void)setReferencesField:(NSString *)newReferencesField;
- (NSString *)getReferencesFieldUID;

- (void)setReferencesTable:(NSString *)newReferencesTable;

- (NSString*) getReferencesTable;
- (NSString *)getReferencesTableUID;
- (void)setReferencesTableUID:(NSString *)newReferencesTableUID;

- (NSString*) getReferenceId;
- (void) setReferenceId:(NSString*) referenceIdString;

- (void) setReferences:(NSString*) table :(NSString*) field;

- (NSArray*) getDependentCompoundKeyFields;

- (void) setSourceForeignKey:(SQLField*) sourceForeignKey ;
- (SQLField*) getSourceForeignKey ;

- (NSString*) exportSQLForeignKey:(NSString*) tableName ;

- (id)indexList ;

- (BOOL)hasWarnings;




@end
