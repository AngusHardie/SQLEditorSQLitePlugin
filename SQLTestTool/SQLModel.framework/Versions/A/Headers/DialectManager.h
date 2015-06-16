/*
 *  DialectManager.h
 *  SQLEditor
 *
 *  Created by Angus W Hardie on Sun Mar 21 2004.
 *  Copyright (c) 2004 MalcolmHardie Software. All rights reserved.
 *
 */
#import <Cocoa/Cocoa.h>
#import "SQLIterator.h"
#import "ExportDialect.h"
#import "SQLExportDialect.h"

/**
	Interface for SQLExporter.DialectManager
**/
@interface DialectManager : NSObject
{
    NSString* _currentDialectName;
	NSMutableArray* _exporterList;
}


+ (DialectManager*)getDialectManager;
- (SQLIterator*)getExporterIterator;
- (SQLExportDialect*)getExporterFromUrl:(NSString*)target ;
- (SQLExportDialect*)getExporterWithName:(NSString*)target;
- (SQLExportDialect*)getExporter;
- (NSString*)extensionForDialect:(NSString*)dialect ;

- (void)addDialect:(ExportDialect*)dialect;

- (NSString*) getIdentifierFromURL:(NSString*) target;

- (void) loadDriverListFromPath: (id) driverListPath;


+ (void)registerDialectExporterWithName:(NSString*)name driver:(NSString*)driver exporterClass:(Class)exporterClass;
+ (void)addDriver:(id)driver forExporterName:(NSString*)name;
@end