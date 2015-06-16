//
//  PluginManager.h
//  SQLEditor
//
/**
 *
 *  @author Angus Hardie
 *  @date 02/12/2004
 *  Copyright 2004 MalcolmHardie Solutions Ltd. All rights reserved.
 **/

#import <Cocoa/Cocoa.h>

/**
 Controller for loading and managing plugins
 **/	
@interface SQLPluginManager : NSObject {
	
	IBOutlet id exportMenu;
	IBOutlet id pluginMenu;
	
	id pluginManager;
}
- (id)init;
+ (SQLPluginManager*)sharedPluginManager;
- (void)dealloc;
- (void)pluginDebug;


- (id)pluginList;

- (id)importPluginForType:(NSString*)pluginType;
- (NSArray*)supportedImportTypes;

- (id)exportPluginForType:(NSString*)pluginType;
- (NSArray*)supportedExportTypes;
- (NSArray*)supportedExportTypes:(BOOL)userDisplayableOnly;

- (id)importPluginForData:(NSData*)data;
@end
