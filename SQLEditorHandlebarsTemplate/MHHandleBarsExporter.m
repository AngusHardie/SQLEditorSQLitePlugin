//
//  MHHandleBarsExporter.m
//  SQLEditorHandlebarsTemplate
//
//  Created by Angus Hardie on 16/06/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions. All rights reserved.
//

#import "MHHandleBarsExporter.h"

#import <JavaScriptCore/JavaScriptCore.h>

#import <HBHandlebars/HBHandlebars.h>

#define EXPORT_SYMBOL_EXTERNAL __attribute__((visibility("default")))
#import <SQLModel/SQLTable.h>
#import <SQLModel/SQLField.h>
#import <SQLModel/SQLContainer.h>
#import <SQLModel/SQLIndex.h>
#import <SQLModel/SQLForeignKey.h>


@interface SQLContainer (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLContainer (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"objectList",@"properties"];
    
}

@end

@interface SQLTable (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLTable (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"fullyQualifiedName",@"name",@"tableType",@"fields",@"properties"];
    
}

@end

@interface SQLField (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLField (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"name",@"type",@"primaryKey",@"isUnique",@"notNull",@"properties"];
    
}

@end

@interface SQLIndex (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLIndex (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"name",@"indexType",@"properties",@"getLabel",@"fieldList"];
    
}

@end


@implementation MHHandleBarsExporter


+ (void)registerTypeTest
{
    
    HBHelperBlock isSQLType = ^(HBHelperCallingInfo* callingInfo)
    {
        // retrieve the value
        id object = callingInfo.context;
        id type = callingInfo[0];
        
        
        
        
        if ([NSStringFromClass([object class]) isEqualToString:type]) {
            
            return callingInfo.statements(callingInfo.context, callingInfo.data);
        } else {
            return callingInfo.inverseStatements(callingInfo.context, callingInfo.data);
        }
        
        
    };
    
    [HBHandlebars registerHelperBlock:isSQLType forName:@"isSQLType"];
    
}


- (NSString*)exportContainer:(id)container withDocumentInfo:(id)documentInfo;
{
    
    
    [MHHandleBarsExporter registerTypeTest];
    
    NSError* error = nil;
    
     NSURL* templateURL = [[NSBundle bundleForClass:[self class]] URLForResource:@"report" withExtension:@"template"];
    
    
    NSString* templateSource = [NSString stringWithContentsOfURL:templateURL encoding:NSUTF8StringEncoding error:&error];
    
    
    
    
    id context = @{ @"container":container};
    


    
    NSString* resultString = [HBHandlebars renderTemplateString:templateSource withContext:context error:&error];
    
    
    
    return resultString;
}

@end
