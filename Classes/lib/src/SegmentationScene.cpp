#include "../include/SegmentationScene.h"
#include "cocos2d.h"
#include "fmod.hpp"
#include <algorithm> // Include the algorithm library for std::shuffle
#include <random>    // Include the random library for std::default_random_engine and std::random_device

USING_NS_CC;

Scene* SegmentationScene::createScene() {
    auto scene = Scene::create();
    auto layer = SegmentationScene::create();
    scene->addChild(layer);
    return scene;
}

bool SegmentationScene::init() {
    if (!Scene::init()) {
        return false;
    }

    // Initialize the FMOD audio system
    FMOD::System* system;
    FMOD::System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, nullptr);

    // Load the background music
    //TODO: find background music and replace path_to_background_music.mp3
    FMOD::Sound* backgroundMusic;
    system->createStream("path_to_background_music.mp3", FMOD_LOOP_NORMAL, nullptr, &backgroundMusic);

    // Play the background music
    FMOD::Channel* channel;
    system->playSound(backgroundMusic, nullptr, false, &channel);

    // Load the image
    auto sprite = Sprite::create("../sampleImages/sf.jpeg");

    // Determine the segment size
    int numPieces = 4; // Change this to the desired number of pieces
    Size imageSize = sprite->getContentSize();
    Size segmentSize(imageSize.width / numPieces, imageSize.height / numPieces);

    // Create a vector to store the segment sprites
    std::vector<Sprite*> segmentSprites;

    //touch listener?
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(SegmentationScene::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(SegmentationScene::onTouchEnded, this);
    listener->onTouchMoved = CC_CALLBACK_2(SegmentationScene::onTouchMoved, this);
    listener->onTouchCancelled = CC_CALLBACK_2(SegmentationScene::onTouchCancelled, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    // Create and position the segment sprites
    for (int i = 0; i < numPieces; i++) {
        for (int j = 0; j < numPieces; j++) {
            // Create a sprite with a specific texture
            auto segmentSprite = Sprite::createWithTexture(sprite->getTexture(), Rect(i * segmentSize.width, j * segmentSize.height, segmentSize.width, segmentSize.height));

            // Set the position of the segment sprite
            segmentSprite->setPosition(Vec2(i * segmentSize.width, j * segmentSize.height));

            // Add the segment sprite to the vector
            segmentSprites.push_back(segmentSprite);

//            auto listener = EventListenerTouchOneByOne::create();
//            listener->onTouchBegan = [](Touch* touch, Event* event) {
//                if (segmentSprite->getBoundingBox().containsPoint(touch->getLocation())) {
//                    // Set the segment sprite as the target for dragging
//                    segmentSprite->setLocalZOrder(1); // Bring the sprite to the front
//                    return true;
//                }
//                return false;
//            };

            // Enable touch events for the segment sprite
//            segmentSprite->onTouchBegan = [segmentSprite](Touch* touch, Event* event) {
//                // Check if the touch is within the segment sprite's bounding box
//                if (segmentSprite->getBoundingBox().containsPoint(touch->getLocation())) {
//                    // Set the segment sprite as the target for dragging
//                    segmentSprite->setLocalZOrder(1); // Bring the sprite to the front
//                    return true;
//                }
//                return false;
//            };

//            listener->onTouchMoved = [](Touch* touch, Event* event) {
//                // Move the segment sprite with the touch movement
//                segmentSprite->setPosition(segmentSprite->getPosition() + touch->getDelta());
//            };
//            segmentSprite->onTouchMoved = [segmentSprite](Touch* touch, Event* event) {
//                // Move the segment sprite with the touch movement
//                segmentSprite->setPosition(segmentSprite->getPosition() + touch->getDelta());
//            };

//            listener->onTouchEnded = [](Touch* touch, Event* event) {
//                // Get the current position of the segment sprite
//                Vec2 currentPosition = segmentSprite->getPosition();
//
//                // Calculate the expected position based on the segment size
//                Vec2 expectedPosition(segmentSize.width * segmentSprite->getTag() % numPieces, segmentSize.height * (numPieces - 1 - segmentSprite->getTag() / numPieces));
//
//                // Calculate the distance between the current position and the expected position
//                float distance = currentPosition.distance(expectedPosition);
//
//                // Define a threshold distance for snapping the segment sprite into place
//                float threshold = segmentSize.width * 0.2;
//
//                // Check if the segment sprite is close enough to the expected position
//                if (distance <= threshold) {
//                    // Snap the segment sprite into place
//                    segmentSprite->setPosition(expectedPosition);
//
//                    // Load the sound effect for connecting puzzle pieces
//                    //TODO: find connect sound and replace path_to_connect_sound.wav
//                    FMOD::Sound* connectSound;
//                    system->createSound("path_to_connect_sound.wav", FMOD_DEFAULT, nullptr, &connectSound);
//
//                    // Play the sound effect for connecting puzzle pieces
//                    system->playSound(connectSound, nullptr, false, nullptr);
//                } else {
//                    // Return the segment sprite to its original position
//                    segmentSprite->setPosition(segmentSprite->getOriginalPosition());
//                }

                // Check if the puzzle is completed
                bool puzzleCompleted = true;
                for (auto sprite : segmentSprites) {
                    if (sprite->getPosition() != sprite->getOriginalPosition()) {
                        puzzleCompleted = false;
                        break;
                    }
                }

                // Play the sound effect for completing the puzzle if it is completed
                if (puzzleCompleted) {
                    // Load the sound effect for completing the puzzle
                    //TODO: find complete sound and replace path_to_complete_sound.wav
                    FMOD::Sound* completeSound;
                    system->createSound("path_to_complete_sound.wav", FMOD_DEFAULT, nullptr, &completeSound);

                    // Play the sound effect for completing the puzzle
                    system->playSound(completeSound, nullptr, false, nullptr);
                }
            };
            //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, segmentSprite);
//            segmentSprite->onTouchEnded = [segmentSprite, segmentSize, numPieces](Touch* touch, Event* event) {
//                // Get the current position of the segment sprite
//                Vec2 currentPosition = segmentSprite->getPosition();
//
//                // Calculate the expected position based on the segment size
//                Vec2 expectedPosition(segmentSize.width * segmentSprite->getTag() % numPieces, segmentSize.height * (numPieces - 1 - segmentSprite->getTag() / numPieces));
//
//                // Calculate the distance between the current position and the expected position
//                float distance = currentPosition.distance(expectedPosition);
//
//                // Define a threshold distance for snapping the segment sprite into place
//                float threshold = segmentSize.width * 0.2;
//
//                // Check if the segment sprite is close enough to the expected position
//                if (distance <= threshold) {
//                    // Snap the segment sprite into place
//                    segmentSprite->setPosition(expectedPosition);
//
//                    // Load the sound effect for connecting puzzle pieces
//                    //TODO: find connect sound and replace path_to_connect_sound.wav
//                    FMOD::Sound* connectSound;
//                    system->createSound("path_to_connect_sound.wav", FMOD_DEFAULT, nullptr, &connectSound);
//
//                    // Play the sound effect for connecting puzzle pieces
//                    system->playSound(connectSound, nullptr, false, nullptr);
//                } else {
//                    // Return the segment sprite to its original position
//                    segmentSprite->setPosition(segmentSprite->getOriginalPosition());
//                }
//
//                // Check if the puzzle is completed
//                bool puzzleCompleted = true;
//                for (auto sprite : segmentSprites) {
//                    if (sprite->getPosition() != sprite->getOriginalPosition()) {
//                        puzzleCompleted = false;
//                        break;
//                    }
//                }
//
//                // Play the sound effect for completing the puzzle if it is completed
//                if (puzzleCompleted) {
//                    // Load the sound effect for completing the puzzle
//                    //TODO: find complete sound and replace path_to_complete_sound.wav
//                    FMOD::Sound* completeSound;
//                    system->createSound("path_to_complete_sound.wav", FMOD_DEFAULT, nullptr, &completeSound);
//
//                    // Play the sound effect for completing the puzzle
//                    system->playSound(completeSound, nullptr, false, nullptr);
//                }
//            };
            //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, segmentSprite);
        }


    // Shuffle the segment sprites
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(segmentSprites.begin(), segmentSprites.end(), rng);

    // Add the shuffled segment sprites to the scene
    for (Sprite* segmentSprite : segmentSprites) {
        addChild(segmentSprite);
    }

    return true;
}

bool SegmentationScene::onTouchBegan(Touch* touch, Event* event) {
    return true;
}

void SegmentationScene::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended");
}

void SegmentationScene::onTouchMoved(Touch* touch, Event* event)
{
    cocos2d::log("touch moved");
}

void SegmentationScene::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");
}