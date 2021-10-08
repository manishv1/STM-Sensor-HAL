/*
 * Copyright (C) 2018 The Android Open Source Project
 * Copyright (C) 2015-2020 STMicroelectronics
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

#pragma once

#include "SWSensorBase.h"

#include <STMSensorsFusion9Axis.h>

namespace stm {
namespace core {

class SWAccelMagnGyroFusion9X : public SWSensorBaseWithPollrate {
protected:
    SensorBaseData outdata;

public:
    SWAccelMagnGyroFusion9X(const char *name, int handle);

    virtual int CustomInit();

    virtual int libsInit(void) override;

    virtual int Enable(int handle, bool enable, bool lock_en_mutex);
    virtual int SetDelay(int handle, int64_t period_ns, int64_t timeout, bool lock_en_mutex);
    virtual void ProcessData(SensorBaseData *data);

private:
    STMSensorsFusion9Axis& sensorsFusion;
};

} // namespace core
} // namespace stm
