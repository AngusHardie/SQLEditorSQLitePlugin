//
//  XMLExport.h
//  SQLEditorUniversal2
//
//  Created by Angus W Hardie on 09/05/2008.
//  Copyright 2008 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface XMLExport : NSObject {

}
+ (NSXMLElement*)cdataElementWithName:(NSString*)name stringValue:(NSString*)string;
@end
