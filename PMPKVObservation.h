//
//  PMPKVO.h
//  PMPKVO Sample App
//
//  Created by Mark Aufflick on 12/03/12.
//  Copyright (c) 2012 Pumptheory Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMPKVObservation;

@interface PMPKVObservation : NSObject

@property (nonatomic, assign) id observee;
@property (nonatomic, assign) id observer;
@property (nonatomic) SEL selector; //eg.  observedChange:(PMPKVObservation *)obs changeDictionary:(NSDictionary *)change
@property (nonatomic, copy) void (^callbackBlock)(PMPKVObservation * observation, NSDictionary * changeDictionary);
@property (nonatomic, copy) NSString * keyPath;
@property NSKeyValueObservingOptions options;
@property (nonatomic, readonly) BOOL isValid;

+ (PMPKVObservation *)observe:(id)observee 
                     observer:(id)observer 
                     selector:(SEL)selector
                      keyPath:(NSString *)keyPath
                      options:(NSKeyValueObservingOptions)options;

+ (PMPKVObservation *)observe:(id)observee 
                      keyPath:(NSString *)keyPath
                      options:(NSKeyValueObservingOptions)options
                     callback:(void (^)(PMPKVObservation * observation, NSDictionary * changeDictionary))callbackBlock;

- (BOOL)observe; // only necessary if you alloc/init yourself
- (void)invalidate; // not necessary if the observation object lifecycle/dealloc will go away at the appropriate time

@end