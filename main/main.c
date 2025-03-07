#include <stdio.h>
#include <inttypes.h>
#include "esp_err.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "freertos/projdefs.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../components/bt_ota.h"
#include "sysdefs.h"


const char* TAG = "main";

static esp_err_t mainInit(void);
static esp_err_t mainTickHandler(void);

void app_main(void) {
  ESP_LOGI(TAG, "App A start!");
  ESP_ERROR_CHECK(mainInit());
  bt_init();

  while (true) {
    ESP_ERROR_CHECK(mainTickHandler());
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

static esp_err_t mainInit(void) {
  return ESP_OK;
}

static esp_err_t mainTickHandler(void) {
  /* 10ms main tick */
  return ESP_OK;
}

const char* getDeviceManufacturer(void) {
  return MANUFACTURER;
}

const char* getDeviceName(void) {
  return DEVICE_NAME;
}

const char* getDeviceSwVer(void) {
  return SW_VER;
}

const char* getDeviceHwVer(void) {
  return HW_VER;
}

