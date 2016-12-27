/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "LatinIME: jni: ProximityInfo"

#include "com_android_inputmethod_keyboard_ProximityInfo.h"

#include "defines.h"
#include "jni.h"
#include "jni_common.h"
#include "suggest/core/layout/proximity_info.h"

#include <algorithm>
#include <cstring>
#include <cmath>

namespace latinime {

static AK_FORCE_INLINE void safeGetOrFillZeroIntArrayRegion(JNIEnv *env, jintArray jArray,
        jsize len, jint *buffer) {
    if (jArray && buffer) {
        env->GetIntArrayRegion(jArray, 0, len, buffer);
    } else if (buffer) {
        memset(buffer, 0, len * sizeof(buffer[0]));
    }
}

static AK_FORCE_INLINE void safeGetOrFillZeroFloatArrayRegion(JNIEnv *env, jfloatArray jArray,
        jsize len, jfloat *buffer) {
    if (jArray && buffer) {
        env->GetFloatArrayRegion(jArray, 0, len, buffer);
    } else if (buffer) {
        memset(buffer, 0, len * sizeof(buffer[0]));
    }
}



static jlong latinime_Keyboard_setProximityInfo(JNIEnv *env, jclass clazz, jstring localeJStr,
        jint displayWidth, jint displayHeight, jint gridWidth, jint gridHeight,
        jint mostCommonkeyWidth, jint mostCommonkeyHeight, jintArray proximityChars, jint keyCount,
        jintArray keyXCoordinates, jintArray keyYCoordinates, jintArray keyWidths,
        jintArray keyHeights, jintArray keyCharCodes, jfloatArray sweetSpotCenterXs,
        jfloatArray sweetSpotCenterYs, jfloatArray sweetSpotRadii) {
    ProximityInfo *proximityInfo = createProximityInfo(env, localeJStr, displayWidth, displayHeight,
            gridWidth, gridHeight, mostCommonkeyWidth, mostCommonkeyHeight, proximityChars,
            keyCount, keyXCoordinates, keyYCoordinates, keyWidths, keyHeights, keyCharCodes,
            sweetSpotCenterXs, sweetSpotCenterYs, sweetSpotRadii);

    return reinterpret_cast<jlong>(proximityInfo);
}


static ProximityInfo createProximityInfo(JNIEnv *env, const jstring localeJStr,
        const int keyboardWidth, const int keyboardHeight, const int gridWidth,
        const int gridHeight, const int mostCommonKeyWidth, const int mostCommonKeyHeight,
        const jintArray proximityChars, const int keyCount, const jintArray keyXCoordinates,
        const jintArray keyYCoordinates, const jintArray keyWidths, const jintArray keyHeights,
        const jintArray keyCharCodes, const jfloatArray sweetSpotCenterXs,
        const jfloatArray sweetSpotCenterYs, const jfloatArray sweetSpotRadii)
        {

    /* Let's check the input array length here to make sure */
    const jsize proximityCharsLength = env->GetArrayLength(proximityChars);
    if (proximityCharsLength != GRID_WIDTH * GRID_HEIGHT * MAX_PROXIMITY_CHARS_SIZE) {
        AKLOGE("Invalid proximityCharsLength: %d", proximityCharsLength);
        ASSERT(false);
        return;
    }
    if (DEBUG_PROXIMITY_INFO) {
        AKLOGI("Create proximity info array %d", proximityCharsLength);
    }
    const jsize localeCStrUtf8Length = env->GetStringUTFLength(localeJStr);
    if (localeCStrUtf8Length >= MAX_LOCALE_STRING_LENGTH) {
        AKLOGI("Locale string length too long: length=%d", localeCStrUtf8Length);
        ASSERT(false);
    }
    static const int MAX_LOCALE_STRING_LENGTH = 10;
    char mLocaleStr[MAX_LOCALE_STRING_LENGTH];
    int *mProximityCharsArray;
    int mKeyXCoordinates[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mKeyYCoordinates[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mKeyWidths[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mKeyHeights[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mKeyCodePoints[MAX_KEY_COUNT_IN_A_KEYBOARD];
    float mSweetSpotCenterXs[MAX_KEY_COUNT_IN_A_KEYBOARD];
    float mSweetSpotCenterYs[MAX_KEY_COUNT_IN_A_KEYBOARD];
    // Sweet spots for geometric input. Note that we have extra sweet spots only for Y coordinates.
    float mSweetSpotCenterYsG[MAX_KEY_COUNT_IN_A_KEYBOARD];
    float mSweetSpotRadii[MAX_KEY_COUNT_IN_A_KEYBOARD];
    std::unordered_map<int, int> mLowerCodePointToKeyMap;
    int mKeyIndexToOriginalCodePoint[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mKeyIndexToLowerCodePointG[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mCenterXsG[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mCenterYsG[MAX_KEY_COUNT_IN_A_KEYBOARD];
    int mKeyKeyDistancesG[MAX_KEY_COUNT_IN_A_KEYBOARD][MAX_KEY_COUNT_IN_A_KEYBOARD];

    env->GetStringUTFRegion(localeJStr, 0, env->GetStringLength(localeJStr), mLocaleStr);
    safeGetOrFillZeroIntArrayRegion(env, proximityChars, proximityCharsLength,
            mProximityCharsArray);
    safeGetOrFillZeroIntArrayRegion(env, keyXCoordinates, KEY_COUNT, mKeyXCoordinates);
    safeGetOrFillZeroIntArrayRegion(env, keyYCoordinates, KEY_COUNT, mKeyYCoordinates);
    safeGetOrFillZeroIntArrayRegion(env, keyWidths, KEY_COUNT, mKeyWidths);
    safeGetOrFillZeroIntArrayRegion(env, keyHeights, KEY_COUNT, mKeyHeights);
    safeGetOrFillZeroIntArrayRegion(env, keyCharCodes, KEY_COUNT, mKeyCodePoints);
    safeGetOrFillZeroFloatArrayRegion(env, sweetSpotCenterXs, KEY_COUNT, mSweetSpotCenterXs);
    safeGetOrFillZeroFloatArrayRegion(env, sweetSpotCenterYs, KEY_COUNT, mSweetSpotCenterYs);
    safeGetOrFillZeroFloatArrayRegion(env, sweetSpotRadii, KEY_COUNT, mSweetSpotRadii);
    return new ProximityInfo(mLocaleStr, displayWidth, displayHeight,
            gridWidth, gridHeight, mostCommonkeyWidth, mostCommonkeyHeight, mProximityCharsArray,
            keyCount, mKeyXCoordinates, mKeyYCoordinates, mKeyWidths, mKeyHeights, mKeyCodePoints,
            mSweetSpotCenterXs, mSweetSpotCenterYs, mSweetSpotRadii);
}


static void latinime_Keyboard_release(JNIEnv *env, jclass clazz, jlong proximityInfo) {
    ProximityInfo *pi = reinterpret_cast<ProximityInfo *>(proximityInfo);
    delete pi;
}

static const JNINativeMethod sMethods[] = {
    {
        const_cast<char *>("setProximityInfoNative"),
        const_cast<char *>("(Ljava/lang/String;IIIIII[II[I[I[I[I[I[F[F[F)J"),
        reinterpret_cast<void *>(latinime_Keyboard_setProximityInfo)
    },
    {
        const_cast<char *>("releaseProximityInfoNative"),
        const_cast<char *>("(J)V"),
        reinterpret_cast<void *>(latinime_Keyboard_release)
    }
};

int register_ProximityInfo(JNIEnv *env) {
    const char *const kClassPathName = "com/android/inputmethod/keyboard/ProximityInfo";
    return registerNativeMethods(env, kClassPathName, sMethods, NELEMS(sMethods));
}
} // namespace latinime
