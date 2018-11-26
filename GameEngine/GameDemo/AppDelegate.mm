//
//  AppDelegate.m
//  GameDemo
//
//  Created by 王兵 on 2018/11/16.
//  Copyright © 2018 王兵. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#include "CApplication.hpp"

@interface AppDelegate ()
{
    UIWindow *window;
    ViewController *viewController;
}
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    
//    CCEAGLView *eaglView = [CCEAGLView viewWithFrame: [window bounds]
//                                         pixelFormat: (NSString*)cocos2d::GLViewImpl::_pixelFormat
//                                         depthFormat: cocos2d::GLViewImpl::_depthFormat
//                                  preserveBackbuffer: NO
//                                          sharegroup: nil
//                                       multiSampling: NO
//                                     numberOfSamples: 0 ];
//
//    [eaglView setMultipleTouchEnabled:NO];
    viewController = [[ViewController alloc] init];
    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:viewController];
    }
    [window makeKeyAndVisible];
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    CApplication::getInstance()->applicationDidEnterBackground();
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    CApplication::getInstance()->applicationWillEnterForeground();
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
