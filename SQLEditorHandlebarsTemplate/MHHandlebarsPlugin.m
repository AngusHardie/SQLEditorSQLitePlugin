//
//  MHTemplateExporter.m
//  TemplateExporter
//
//  Created by Angus Hardie on 05/04/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions. All rights reserved.
//

#import "MHHandlebarsPlugin.h"
#import "MHHandlebarsExporter.h"
#define EXPORT_SYMBOL_EXTERNAL __attribute__((visibility("default")))
#import <SQLModel/SQLContainer.h>

@interface NSObject (documentModel)

- (id)getModel;
- (id)model;
@end

@interface NSObject (modelContainer)
- (SQLContainer*)getContainer;
- (SQLContainer*)container;
@end


@implementation MHHandlebarsPlugin



#define kPluginName @"HTML Single Page Exporter"

- (void)initPlugin:(id)sender
{
    NSLog(@"HTML Single Page Exporter 1.0");
    
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
    
    
    return @"html";
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
    
    return [[MHHandleBarsExporter alloc] init];
}

//- (BOOL)exportContainer:(id)container toFileURL:(NSURL *)outputURL
//{
//    id plugin = [self exporter];
//    
//    
//    [plugin exportContainer:container toFileURL:outputURL];
//    
//    return YES;
//    
//}
//
//- (BOOL)exportDocument:(id)document toPath:(id)fileSavePath options:(id)exportOptions
//{
//    
//    
//    
//    id container = [[document model] container];
//    
//    
//    return [self exportContainer:container toFileURL:[NSURL fileURLWithPath:fileSavePath]];
//    
//    
//}

@end
