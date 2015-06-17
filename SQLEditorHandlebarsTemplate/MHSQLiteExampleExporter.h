//
//  MHHandleBarsExporter.h
//  SQLEditorHandlebarsTemplate
//
//  Created by Angus Hardie on 16/06/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions.
//
//  BSD License Applies

#import <Foundation/Foundation.h>

@class JSContext;

@interface MHSQLiteExampleExporter : NSObject



@property (retain) JSContext* jsContext;

- (NSString*)exportContainer:(id)container withDocumentInfo:(id)documentInfo;


@end
