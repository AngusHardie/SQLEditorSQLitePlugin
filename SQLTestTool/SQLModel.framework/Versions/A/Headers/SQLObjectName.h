//
//  SQLObjectName.h
//  SQLEditorUniversal2
//
//  Created by Angus W Hardie on 22/06/2008.
//  Copyright 2008 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SQLObjectName : NSObject {

    NSString* _baseName;
    NSMutableArray* _qualifierList;
    
    NSString* _alias;
}

+ (SQLObjectName*)objectNameWithBaseName:(NSString*)baseName;

- (id)initWithBaseName:(NSString*)baseName;

- (void)addQualifier:(NSString*)qualifier;


- (NSString*)fullyQualifiedName;
- (NSMutableArray*)qualifierList;


- (NSString *)baseName;
- (void)setBaseName:(NSString *)value;

- (NSString *)alias;
- (void)setAlias:(NSString *)value;

- (NSString*)aliasString;
@end
