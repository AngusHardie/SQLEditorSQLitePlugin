//
//  Parser.h
//  XMLParserTest
//
//  Created by Angus Hardie on 07/06/2005.
//  Copyright 2005 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MHStack.h"

#if __MAC_OS_X_VERSION_MAX_ALLOWED >= 1060
@interface Parser : NSObject <NSXMLParserDelegate> 
#else
@interface Parser : NSObject 
#endif
{
	NSMutableString* currentStringValue;
	NSString* curElementName;
	
	MHStack* objectStack;
    id topObject;
	id container;
	
	BOOL _recoveryMode;
}
- (BOOL)parseXMLFile:(NSString *)pathToFile withContainer:(id)container;
- (id)parseXMLFromString:(NSString*)data;
- (BOOL)parseXMLFromString:(NSString*)data withContainer:(id)newContainer ;
- (id)parseXMLFromPath:(NSString*)path;
- (BOOL)parseXMLFromData:(NSData*)data withContainer:(id)newContainer;
- (BOOL)parseXMLWithRecoveryFromData:(NSData*)data withContainer:(id)newContainer;
@end
