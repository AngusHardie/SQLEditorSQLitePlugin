/*
 *  SQLForeignKeyEntry.h
 *  SQLEditorUniversal
 *
 *  Created by Angus W Hardie on 30/01/2009.
 *  Copyright 2009 MalcolmHardie Solutions Ltd. All rights reserved.
 *
 */

#import <Cocoa/Cocoa.h>
#import "SQLField.h"
#import "SQLIterator.h"

@class SQLTable;
/**
 Interface for SQLModel.SQLForeignKey
 **/
EXPORT_SYMBOL_EXTERNAL
@interface SQLForeignKeyEntry  : SQLObject
{

	SQLField* _source;
	SQLField* _target;

}


- (SQLForeignKeyEntry*)initWithSource:(SQLField*)source target:(SQLField*)target;


- (SQLField*)getTarget;
- (SQLField*)getSource;

- (void)setTarget:(SQLField*)target;
- (void)setSource:(SQLField*)source;


- (void)setSourceFromUid:(SQLTable*)table :(NSString*)uid;
- (void)setTargetFromUid:(SQLTable*)table :(NSString*)uid;


- (void)setTargetByName:(NSString*) targetName;
@end