//
//  MHHandleBarsExporter.m
//  SQLEditorHandlebarsTemplate
//
//  Created by Angus Hardie on 16/06/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions. 
//
//  BSD License Applies

#import "MHSQLiteExampleExporter.h"

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
    
    
    return @[@"objectList",@"tables",@"views",@"comments",@"canvasAreas",@"properties"];
    
}

- (NSArray*)childrenOfType:(Class)classType
{
    
    NSMutableArray* fields = [NSMutableArray array];
    
    for (id entry in [self objectList]) {
        
        if ([entry isKindOfClass:classType]) {
            
            [fields addObject:entry];
        }
        
    }
    return fields;
}

- (NSArray*)tables
{
    
    return [self childrenOfType:[SQLTable class]];
}

- (NSArray*)comments
{
    
    return [self childrenOfType:[SQLComment class]];
}

- (NSArray*)canvasAreas
{
    
    return [self childrenOfType:NSClassFromString(@"SQLCanvasArea")];
}

- (NSArray*)views
{
    
    return [self childrenOfType:NSClassFromString(@"SQLView")];
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
- (NSArray*)childrenOfType:(Class)classType;
@end

@implementation SQLTable (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"fullyQualifiedName",@"name",@"schemaName",@"tableType",@"columns",@"fields",@"indexes",@"foreignKeys",@"foreignKeyFieldsInTable",@"properties"];
    
}


- (NSArray*)childrenOfType:(Class)classType
{
    
    NSMutableArray* fields = [NSMutableArray array];
    
    for (id entry in [self fields]) {
        
        if ([entry isKindOfClass:classType]) {
            
            [fields addObject:entry];
        }
        
    }
    return fields;
}

- (NSArray*)columns
{
    
    return [self childrenOfType:[SQLField class]];
}

- (NSArray*)indexes
{
    
    return [self childrenOfType:[SQLIndex class]];
}

- (NSArray*)foreignKeys
{
    
    return [self childrenOfType:[SQLForeignKey class]];
}



@end

@interface SQLField (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLField (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"name",@"type",@"primaryKey",@"parentTable",@"isUnique",@"notNull",@"defaultValue",@"getAutoIncrement",@"getReferencesString",@"fkField",@"properties"];
    
}

@end

@interface SQLForeignKey (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLForeignKey (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"name",@"type",@"getTargetTable",@"getSourceList",@"sourceListString",@"targetListString",@"getTargetList",@"properties"];
    
}

- (NSString*)sourceListString
{
    
    return [[self getSourceList] componentsJoinedByString:@","];
}

- (NSString*)targetListString
{
    
    return [[self getTargetList] componentsJoinedByString:@","];
}

@end

@interface SQLIndex (handlebars)
+ (NSArray*) validKeysForHandlebars;
@end

@implementation SQLIndex (handlebars)

+ (NSArray*) validKeysForHandlebars
{
    
    
    return @[@"name",@"indexType",@"properties",@"getLabel",@"columnListString",@"parent",@"fieldList"];
    
}


- (NSString*)columnListString
{
    
    NSArray* nameList = [self getFieldNameList];
    
    return [nameList componentsJoinedByString:@","];
}

@end



@implementation MHSQLiteExampleExporter


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
    
    
    [MHSQLiteExampleExporter registerTypeTest];
    
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


// hack for older SQLEditor versions
// this method may get called, just return NO
- (BOOL)shouldQuoteDefaultFieldValue
{
    
    return NO;
}

@end
