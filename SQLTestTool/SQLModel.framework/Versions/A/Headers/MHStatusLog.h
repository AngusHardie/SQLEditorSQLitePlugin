//
//  MHStatusLog.h
//  SQLEditor-17
//
//  Created by Angus Hardie on 28/05/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MHStatusEvent;

@interface MHStatusLog : NSObject


@property (retain) NSMutableArray* events;

@property (retain) NSMutableArray* observers;

- (void)addEvent:(MHStatusEvent*)event;
- (void)removeEvent:(MHStatusEvent*)event;
- (void)removeAllEvents;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;


@end
