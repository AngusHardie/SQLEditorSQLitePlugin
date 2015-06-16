//
//  SQLNameMatch.h
//  SQLEditorUniversal2
//
//  Created by Angus W Hardie on 12/05/2008.
//  Copyright 2008 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SQLObjectContainer.h"

@class SQLObject;

@interface SQLNameMatch : NSObject {

}
+ (NSString*) getValidNameForObject:(SQLObject*) object originalName:(NSString*) originalName container:(id <SQLObjectContainer>)container canAddSchema:(BOOL)canAddSchema;
+ (NSString*) getValidName:(NSString*) originalName container:(id <SQLObjectContainer>)container;
+ (BOOL) isObjectNamePresent:(NSString*) tableName container:(id <SQLObjectContainer>)container;



+ (BOOL) isObjectNamePresent:(NSString*) tableName container:(id <SQLObjectContainer>)container curObject:(SQLObject*)curObject;
@end
