// MESSAGE SET_MODE PACKING

#define MAVLINK_MSG_ID_SET_MODE 11

typedef struct __mavlink_set_mode_t
{
 uint16_t custom_mode; ///< The new autopilot-specific mode. This field can be ignored by an autopilot.
 uint8_t target_system; ///< The system setting the mode
 uint8_t base_mode; ///< The new base mode
} mavlink_set_mode_t;

#define MAVLINK_MSG_ID_SET_MODE_LEN 4
#define MAVLINK_MSG_ID_11_LEN 4



#define MAVLINK_MESSAGE_INFO_SET_MODE { \
	"SET_MODE", \
	3, \
	{  { "custom_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_set_mode_t, custom_mode) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_set_mode_t, target_system) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_set_mode_t, base_mode) }, \
         } \
}


/**
 * @brief Pack a set_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system The system setting the mode
 * @param base_mode The new base mode
 * @param custom_mode The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t base_mode, uint16_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint16_t(buf, 0, custom_mode);
	_mav_put_uint8_t(buf, 2, target_system);
	_mav_put_uint8_t(buf, 3, base_mode);

        memcpy(_MAV_PAYLOAD(msg), buf, 4);
#else
	mavlink_set_mode_t packet;
	packet.custom_mode = custom_mode;
	packet.target_system = target_system;
	packet.base_mode = base_mode;

        memcpy(_MAV_PAYLOAD(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_MODE;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 197);
}

/**
 * @brief Pack a set_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system The system setting the mode
 * @param base_mode The new base mode
 * @param custom_mode The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t base_mode,uint16_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint16_t(buf, 0, custom_mode);
	_mav_put_uint8_t(buf, 2, target_system);
	_mav_put_uint8_t(buf, 3, base_mode);

        memcpy(_MAV_PAYLOAD(msg), buf, 4);
#else
	mavlink_set_mode_t packet;
	packet.custom_mode = custom_mode;
	packet.target_system = target_system;
	packet.base_mode = base_mode;

        memcpy(_MAV_PAYLOAD(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_MODE;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 197);
}

/**
 * @brief Encode a set_mode struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
	return mavlink_msg_set_mode_pack(system_id, component_id, msg, set_mode->target_system, set_mode->base_mode, set_mode->custom_mode);
}

/**
 * @brief Send a set_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system The system setting the mode
 * @param base_mode The new base mode
 * @param custom_mode The new autopilot-specific mode. This field can be ignored by an autopilot.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_mode_send(mavlink_channel_t chan, uint8_t target_system, uint8_t base_mode, uint16_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint16_t(buf, 0, custom_mode);
	_mav_put_uint8_t(buf, 2, target_system);
	_mav_put_uint8_t(buf, 3, base_mode);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, buf, 4, 197);
#else
	mavlink_set_mode_t packet;
	packet.custom_mode = custom_mode;
	packet.target_system = target_system;
	packet.base_mode = base_mode;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, (const char *)&packet, 4, 197);
#endif
}

#endif

// MESSAGE SET_MODE UNPACKING


/**
 * @brief Get field target_system from set_mode message
 *
 * @return The system setting the mode
 */
static inline uint8_t mavlink_msg_set_mode_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field base_mode from set_mode message
 *
 * @return The new base mode
 */
static inline uint8_t mavlink_msg_set_mode_get_base_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field custom_mode from set_mode message
 *
 * @return The new autopilot-specific mode. This field can be ignored by an autopilot.
 */
static inline uint16_t mavlink_msg_set_mode_get_custom_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a set_mode message into a struct
 *
 * @param msg The message to decode
 * @param set_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_mode_decode(const mavlink_message_t* msg, mavlink_set_mode_t* set_mode)
{
#if MAVLINK_NEED_BYTE_SWAP
	set_mode->custom_mode = mavlink_msg_set_mode_get_custom_mode(msg);
	set_mode->target_system = mavlink_msg_set_mode_get_target_system(msg);
	set_mode->base_mode = mavlink_msg_set_mode_get_base_mode(msg);
#else
	memcpy(set_mode, _MAV_PAYLOAD(msg), 4);
#endif
}
