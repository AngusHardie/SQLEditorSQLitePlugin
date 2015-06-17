//
//  MHTemplateExporter.m
//  TemplateExporter
//
//  Created by Angus Hardie on 05/04/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions.
//
//  BSD License Applies

#import "MHSQLiteExamplePlugin.h"
#import "MHSQLiteExampleExporter.h"
#define EXPORT_SYMBOL_EXTERNAL __attribute__((visibility("default")))
#import <SQLModel/SQLContainer.h>

@interface NSObject (documentModel)

- (id)getModel;
- (id)model;
@end

@interface NSObject (modelContainer)
- (SQLContainer*)getContainer;
- (SQLContainer*)container;
- (id)getDocumentInfo;
@end


@implementation MHSQLiteExamplePlugin



#define kPluginName @"SQLite Example Plugin"

- (void)initPlugin:(id)sender
{
    NSLog(@"SQLite Example Plugin 1.0");
    
}

- (NSArray*)supportedImportTypes
{
    
    
    return @[];
}

- (BOOL)canImportType:(id)type
{
    
    return NO;
    
}


- (NSArray*)supportedExportTypes;
{
    
    return [NSArray arrayWithObjects:kPluginName,nil];
}


- (NSString*)exportFileExtension
{
    
    
    return @"sql";
}

- (BOOL)canExportType:(id)type
{
    
    if ([type isEqualToString:kPluginName]) {
        return YES;
    }
    
    return NO;
}

- (BOOL)exportIsUserDisplayable
{
    
    return NO;
}


- (id)exporter
{
    
    return [[MHSQLiteExampleExporter alloc] init];
}



- (NSString*)exportDocument:(id)document
{
    
    id container = [[document model] container];
    
    return [[self exporter] exportContainer:container withDocumentInfo:[[document model] getDocumentInfo]];
    
}


@end
