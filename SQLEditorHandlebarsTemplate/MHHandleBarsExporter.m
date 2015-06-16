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



@implementation MHHandleBarsExporter


- (NSString*)exportContainer:(id)container withDocumentInfo:(id)documentInfo;
{
    
    NSError* error = nil;
    
     NSURL* templateURL = [[NSBundle bundleForClass:[self class]] URLForResource:@"report" withExtension:@"template"];
    
    
    NSString* templateSource = [NSString stringWithContentsOfURL:templateURL encoding:NSUTF8StringEncoding error:&error];
    
    
    
    
    id context = @{ @"container":container};
    
    NSString* resultString = [HBHandlebars renderTemplateString:templateSource withContext:context error:&error];
    
    
    
    return resultString;
}

@end
