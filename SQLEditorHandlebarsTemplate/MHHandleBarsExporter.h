//
//  MHHandleBarsExporter.h
//  SQLEditorHandlebarsTemplate
//
//  Created by Angus Hardie on 16/06/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JSContext;

@interface MHHandleBarsExporter : NSObject



@property (retain) JSContext* jsContext;

- (NSString*)exportContainer:(id)container withDocumentInfo:(id)documentInfo;


@end
