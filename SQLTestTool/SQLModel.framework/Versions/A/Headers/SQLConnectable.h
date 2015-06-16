/*
 *  SQLConnectableObject.h
 *  SQLEditorUniversal
 *
 *  Created by Angus Hardie on 07/05/2009.
 *  Copyright 2009 MalcolmHardie Solutions Limited and Angus W Hardie. All rights reserved.
 *
 */

@class SQLField;

typedef int SQLCardinalityType ;
typedef int SQLUpdateOrDeleteActionType;

@protocol SQLConnectable

- (SQLField*) getFkField;
- (void) setFkField:(SQLField*)field;
- (void)setDefaultCardinalityForImport;
- (void)setDefaultCardinalityForCreatedKey;


- (SQLCardinalityType) getSourceCardinality;
- (void) setSourceCardinality:(SQLCardinalityType) cardinality;
- (SQLCardinalityType) getDestinationCardinality;
- (void) setDestinationCardinality:(SQLCardinalityType) cardinality;

- (SQLCardinalityType)sourceCardinality;
- (SQLCardinalityType) destinationCardinality;

- (SQLUpdateOrDeleteActionType)getDeleteAction;
- (SQLUpdateOrDeleteActionType)deleteAction;
- (void)setDeleteAction:(SQLUpdateOrDeleteActionType)newAction;

- (void) setUpdateAction:(SQLUpdateOrDeleteActionType)updateAction;
- (SQLUpdateOrDeleteActionType)updateAction;


- (NSString*)foreignKeyName;
@end

