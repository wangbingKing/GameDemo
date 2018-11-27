//
//  ViewController.m
//  GameDemo
//
//  Created by 王兵 on 2018/11/20.
//  Copyright © 2018 王兵. All rights reserved.
//

#import "ViewController.h"
#include "CApplication.hpp"
#include "CESContext.hpp"

@interface ViewController ()

@property (strong, nonatomic) EAGLContext *context;
@property (strong, nonatomic) GLKBaseEffect *effect;
@property (nonatomic, assign) BOOL origntationsLanscape;

- (void)tearDownGL;
- (BOOL)prefersStatusBarHidden;
- (void)changeScreenOrigntation:(UIInterfaceOrientation)orientation;
@end

@implementation ViewController

- (instancetype)init {
    self = [super init];
    if (self) {
        self.origntationsLanscape = true;
        self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
        if (!self.context)
        {
            NSLog(@"Failed to create ES context");
        }
        GLKView *view = (GLKView *)self.view;
        view.context = self.context;
        view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    }
    return self;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    [EAGLContext setCurrentContext:self.context];
    CApplication::getInstance()->run();
}

- (void)tearDownGL
{
    [EAGLContext setCurrentContext:self.context];
    CApplication::getInstance()->tearDownGL();
}

- (void)update
{
    CApplication::getInstance()->update(self.timeSinceLastUpdate);
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    CApplication::getInstance()->drawCell((int)view.drawableWidth,(int)view.drawableHeight);
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations
{
    if (self.origntationsLanscape) {
        return UIInterfaceOrientationMaskLandscape;
    }else{
        return UIInterfaceOrientationMaskPortrait;
    }
}

// For ios6, use supportedInterfaceOrientations & shouldAutorotate instead
//- (NSUInteger) supportedInterfaceOrientations{
//    return UIInterfaceOrientationMaskLandscape;
//}

- (BOOL) shouldAutorotate {
    return YES;
}


-(UIInterfaceOrientation) preferredInterfaceOrientationForPresentation{
    
    return UIInterfaceOrientationLandscapeRight;
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
    [super didRotateFromInterfaceOrientation:fromInterfaceOrientation];
//
//    cocos2d::GLView *glview = cocos2d::Director::getInstance()->getOpenGLView();
//
//    if (glview)
//    {
//        CCEAGLView *eaglview = (CCEAGLView*) glview->getEAGLView();
//
//        if (eaglview)
//        {
//            CGSize s = CGSizeMake([eaglview getWidth], [eaglview getHeight]);
//            cocos2d::Application::getInstance()->applicationScreenSizeChanged((int) s.width, (int) s.height);
//        }
//    }
}

- (void)changeScreenOrigntation:(UIInterfaceOrientation)orientation
{
//    if(orientation == UIInterfaceOrientationPortrait){
//        [self setOrigntationsLanscape:false];
//    }else{
//        [self setOrigntationsLanscape:true];
//    }
//
//    if ([[UIDevice currentDevice] respondsToSelector:@selector(setOrientation:)]) {
//        SEL selector             = NSSelectorFromString(@"setOrientation:");
//        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:[UIDevice instanceMethodSignatureForSelector:selector]];
//        [invocation setSelector:selector];
//        [invocation setTarget:[UIDevice currentDevice]];
//        int val                  = orientation;
//        // 从2开始是因为0 1 两个参数已经被selector和target占用
//        [invocation setArgument:&val atIndex:2];
//        [invocation invoke];
//    }
}

//fix not hide status on ios7
- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

@end
