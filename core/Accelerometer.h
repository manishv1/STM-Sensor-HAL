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

#include "HWSensorBase.h"

namespace stm {
namespace core {

/*
 * class Accelerometer
 */
class Accelerometer : public HWSensorBaseWithPollrate {
private:
#if defined(CONFIG_ST_HAL_ADDITIONAL_INFO_ENABLED)
    size_t getSensorAdditionalInfoPayLoadFramesArray(additional_info_event_t **array_sensorAdditionalInfoPLFrames);
#endif /* CONFIG_ST_HAL_ADDITIONAL_INFO_ENABLED */

public:
    Accelerometer(HWSensorBaseCommonData *data, const char *name,
                  struct device_iio_sampling_freqs *sfa, int handle,
                  unsigned int hw_fifo_len, float power_consumption, bool wakeup);

    virtual int Enable(int handle, bool enable, bool lock_en_mutex);
    virtual void ProcessData(SensorBaseData *data);
};

} // namespace core
} // namespace stm