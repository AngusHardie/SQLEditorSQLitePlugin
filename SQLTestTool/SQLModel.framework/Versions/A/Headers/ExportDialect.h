//
//  ExportDialect.java
//  SQLEditor
//
//  Created by Angus Hardie on 04/06/2005.
//  Copyright 2005 MalcolmHardie Solutions Ltd. All rights reserved.
//


#import <Cocoa/Cocoa.h>
#import "SQLIterator.h"
/**
	Interface for SQLExporter.ExportDialect
**/
@interface ExportDialect : NSObject
{
	id _properties;
	id driverClassPathList;
}

- (NSString*) getName;
- (NSString*) getUrl;
- (id)getExporter;
- (void)setExporter:(id)exporter;
- (id)exporter;

+ (id)dialectWithName:(id)name driver:(id)driver exporter:(id)exporter;
+ (id)dialectWithName:(id)name;

- (id)initWithName:(id)name;
- (id)initWithName:(id)name driver:(id)driver exporter:(id)exporter;
- (id)propertiesList;
- (void)addDriverClassPath:(id)classPathString;

- (BOOL)exporterSupportsDriver:(id)driverClassPath;
@end