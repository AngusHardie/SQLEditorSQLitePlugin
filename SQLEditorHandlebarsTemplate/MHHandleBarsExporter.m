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
#import <SQLModel/SQLComment.h>

@interface SQLContainer (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLContainer (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"objectList",@"properties"];
    
}

@end

@interface SQLComment (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLComment (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"name",@"comment",@"properties"];
    
}

@end

@interface SQLTable (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLTable (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"fullyQualifiedName",@"name",@"schemaName",@"tableType",@"fields",@"properties"];
    
}

@end

@interface SQLField (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLField (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"name",@"type",@"primaryKey",@"isUnique",@"notNull",@"defaultValue",@"getAutoIncrement",@"properties"];
    
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


- (void)registerJavascriptHelpersFromScriptURL:(NSURL*)scriptURL
{
    
    NSError* error = nil;
    
    self.jsContext = [[JSContext alloc] init];
    
    [self.jsContext setExceptionHandler:^(JSContext * context, JSValue * value) {
        
        NSLog(@"Javascript Exception: %@", value);
    }];
    
    
    NSString* scriptSource = [NSString stringWithContentsOfURL:scriptURL encoding:NSUTF8StringEncoding error:&error];

    
    [self.jsContext evaluateScript:scriptSource];
    
    
    JSValue* filterList = [self.jsContext[@"filterList"] callWithArguments:@[]];
    
    
    
    
    
    for (id entry in [filterList toArray]) {
        
        NSString* methodName = [entry copy];
        
        __weak  JSContext* context = self.jsContext;
        
        HBHelperBlock helperBlock = ^(HBHelperCallingInfo* callingInfo)
        {
            
            //NSLog(@"%@ parameters = %@",methodName,callingInfo[0]);
            
            
            NSMutableArray* args = [NSMutableArray array];
            
            for (id entry in [callingInfo positionalParameters]) {
                
                
                [args addObject:[JSValue valueWithObject:entry inContext:self.jsContext]];
            }
            
            return [[context[methodName] callWithArguments:args] toString];
        };
        
        [HBHandlebars registerHelperBlock:helperBlock forName:methodName];

        
        context = nil;
        
    }
    
    
    
    
}


- (NSString*)exportContainer:(id)container withDocumentInfo:(id)documentInfo;
{
    
    
    [MHHandleBarsExporter registerTypeTest];
    
    NSError* error = nil;
    
    NSURL* templateURL = [[NSBundle bundleForClass:[self class]] URLForResource:@"report" withExtension:@"template"];
    NSURL* scriptURL = [[NSBundle bundleForClass:[self class]] URLForResource:@"report" withExtension:@"js"];

    

    
    
    NSString* templateSource = [NSString stringWithContentsOfURL:templateURL encoding:NSUTF8StringEncoding error:&error];
    
    
    if (scriptURL) {
        [self registerJavascriptHelpersFromScriptURL:scriptURL];
    }
    
    id context = @{ @"container":container};
    


    
    NSString* resultString = [HBHandlebars renderTemplateString:templateSource withContext:context error:&error];
    
    
    
    return resultString;
}

@end
