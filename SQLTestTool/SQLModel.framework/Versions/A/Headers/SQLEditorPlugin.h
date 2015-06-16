//
//  SQLEditorPlugin.h
//  SQLEditor
//
/**
 *
 *  @author Angus Hardie
 *  @date 03/12/2004
 *  Copyright 2004-2007 MalcolmHardie Solutions Ltd. All rights reserved.
 **/

#import <Cocoa/Cocoa.h>

@class SQLContainer;
/**
 Interface that plugins must implement
 **/
@interface SQLEditorPlugin : NSObject {
	
}
- (void)initPlugin:(id)manager;
- (NSString*)type;


- (NSString*)importFile:(NSString*)filePath error:(NSError**)error;


- (BOOL)canImportType:(id)type;
- (BOOL)isXMLImportType;

- (NSArray*)supportedExportTypes;

- (NSString*)exportDocument:(id)document;
- (NSString*)exportContainer:(id)container withDocumentInfo:(id)documentInfo;

- (NSString*)exportFileExtension;
- (NSString*)lastImportType;

- (id)exporter;

- (NSString*)validFileNameFromName:(NSString*)inputString preDisplay:(BOOL)preDisplay forContainer:(SQLContainer*)container;
@end
