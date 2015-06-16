//
//  MHStringUtils.h
//  XMLParserTest
//
//  Created by Angus Hardie on 12/01/2006.
//  Copyright 2006 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface MHStringUtils : NSObject {

}
+ (NSString*)implode:(NSArray*)objectList;
+ (NSString*) implode:(id)objectList withGlue:(id)glue;

+ (NSString*)capitalizeFirstCharacterOfString:(NSString*)inputString;

@end
