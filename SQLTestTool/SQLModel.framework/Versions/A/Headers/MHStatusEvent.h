//
//  MHStatusEvent.h
//  SQLEditor-17
//
//  Created by Angus Hardie on 28/05/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    MHStatusEventOK,
    MHStatusEventWarning,
    MHStatusEventFailure,
    MHStatusEventCancelled
} MHStatusEventType;

@interface MHStatusEvent : NSObject


@property (copy) NSDate* date;
@property (copy) NSString* summary;
@property (copy) NSString* detail;
@property (copy) NSURL* outputFileURL;

@property (assign) BOOL isWarning;

@property (copy) NSString* logFileText;

@property (assign) MHStatusEventType status;

@property (retain,readonly) NSMutableArray* warningList;


@property (assign) SEL infoButtonAction;
@property (assign) id infoButtonTarget;

@property (retain) id infoButtonObject;


+ (MHStatusEvent*)statusEvent:(MHStatusEventType)status;

- (void)setLogViewController:(id)logViewController;
- (void)addWarningList:(NSArray*)parseExceptionList;
@end
