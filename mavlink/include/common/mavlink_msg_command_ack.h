// MESSAGE COMMAND_ACK PACKING

#define MAVLINK_MSG_ID_COMMAND_ACK 77

typedef struct __mavlink_command_ack_t
{
 uint16_t command; ///< Command ID, as defined by MAV_CMD enum.
 uint8_t result; ///< 1: Command ACCEPTED and EXECUTED, 1: Command TEMPORARY REJECTED/DENIED, 2: Command PERMANENTLY DENIED, 3: Command UNKNOWN/UNSUPPORTED, 4: Command executed, but failed
} mavlink_command_ack_t;

#define MAVLINK_MSG_ID_COMMAND_ACK_LEN 3
#define MAVLINK_MSG_ID_77_LEN 3



#define MAVLINK_MESSAGE_INFO_COMMAND_ACK { \
	"COMMAND_ACK", \
	2, \
	{  { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_command_ack_t, command) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_command_ack_t, result) }, \
         } \
}


/**
 * @brief Pack a command_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param result 1: Command ACCEPTED and EXECUTED, 1: Command TEMPORARY REJECTED/DENIED, 2: Command PERMANENTLY DENIED, 3: Command UNKNOWN/UNSUPPORTED, 4: Command executed, but failed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t command, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, command);
	_mav_put_uint8_t(buf, 2, result);

        memcpy(_MAV_PAYLOAD(msg), buf, 3);
#else
	mavlink_command_ack_t packet;
	packet.command = command;
	packet.result = result;

        memcpy(_MAV_PAYLOAD(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK;
	return mavlink_finalize_message(msg, system_id, component_id, 3, 143);
}

/**
 * @brief Pack a command_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param result 1: Command ACCEPTED and EXECUTED, 1: Command TEMPORARY REJECTED/DENIED, 2: Command PERMANENTLY DENIED, 3: Command UNKNOWN/UNSUPPORTED, 4: Command executed, but failed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t command,uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, command);
	_mav_put_uint8_t(buf, 2, result);

        memcpy(_MAV_PAYLOAD(msg), buf, 3);
#else
	mavlink_command_ack_t packet;
	packet.command = command;
	packet.result = result;

        memcpy(_MAV_PAYLOAD(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 3, 143);
}

/**
 * @brief Encode a command_ack struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_ack_t* command_ack)
{
	return mavlink_msg_command_ack_pack(system_id, component_id, msg, command_ack->command, command_ack->result);
}

/**
 * @brief Send a command_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param result 1: Command ACCEPTED and EXECUTED, 1: Command TEMPORARY REJECTED/DENIED, 2: Command PERMANENTLY DENIED, 3: Command UNKNOWN/UNSUPPORTED, 4: Command executed, but failed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_ack_send(mavlink_channel_t chan, uint16_t command, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, command);
	_mav_put_uint8_t(buf, 2, result);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK, buf, 3, 143);
#else
	mavlink_command_ack_t packet;
	packet.command = command;
	packet.result = result;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK, (const char *)&packet, 3, 143);
#endif
}

#endif

// MESSAGE COMMAND_ACK UNPACKING


/**
 * @brief Get field command from command_ack message
 *
 * @return Command ID, as defined by MAV_CMD enum.
 */
static inline uint16_t mavlink_msg_command_ack_get_command(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field result from command_ack message
 *
 * @return 1: Command ACCEPTED and EXECUTED, 1: Command TEMPORARY REJECTED/DENIED, 2: Command PERMANENTLY DENIED, 3: Command UNKNOWN/UNSUPPORTED, 4: Command executed, but failed
 */
static inline uint8_t mavlink_msg_command_ack_get_result(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a command_ack message into a struct
 *
 * @param msg The message to decode
 * @param command_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_ack_decode(const mavlink_message_t* msg, mavlink_command_ack_t* command_ack)
{
#if MAVLINK_NEED_BYTE_SWAP
	command_ack->command = mavlink_msg_command_ack_get_command(msg);
	command_ack->result = mavlink_msg_command_ack_get_result(msg);
#else
	memcpy(command_ack, _MAV_PAYLOAD(msg), 3);
#endif
}
