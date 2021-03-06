/**
 * Copyright (c) 2017-present, Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */
/* can be included multiple times */

#ifndef STAT_DEFINE
  #error STAT_DEFINE() macro not defined
  #define STAT_DEFINE(...)
#endif

// Stats shared between server and client

// number of MetaDataLogReaders created
STAT_DEFINE(metadata_log_readers_created, SUM)
// number of MetaDataLogReaders started
STAT_DEFINE(metadata_log_readers_started, SUM)
// number of MetaDataLogReaders finished
STAT_DEFINE(metadata_log_readers_finalized, SUM)

// Number of failures to deliver a metadata log record upon request because of
// empty metadata log or malformed records
STAT_DEFINE(metadata_log_read_failed, SUM)

// Number of CONFIG_CHANGED_Messages received with Action::Reload.
STAT_DEFINE(config_changed_reload, SUM)
// Number of CONFIG_CHANGED_Messages ignored because the config is already
// up-to-date.
STAT_DEFINE(config_changed_ignored_uptodate, SUM)
// Number of CONFIG_CHANGED_Messages ignored because the config is not trusted.
STAT_DEFINE(config_changed_ignored_not_trusted, SUM)
// Number of CONFIG_CHANGED_Messages ignored because one with same or newer
// config is already being processed.
STAT_DEFINE(config_changed_ignored_update_in_progress, SUM)
// Number of config updates that occurred as a result of
// CONFIG_CHANGED_Messages.
STAT_DEFINE(config_changed_update, SUM)

// number of times nodeset finder got metadata from sequencer
STAT_DEFINE(nodeset_finder_read_from_sequencer, SUM)
// number of times nodeset finder got metadata from metadata log
STAT_DEFINE(nodeset_finder_read_from_metadata_log, SUM)
// number of times nodeset finder failed to get metadata from sequencer
// and fallback to read from metadata log
STAT_DEFINE(nodeset_finder_fallback_to_metadata_log, SUM)

// LogsConfigManager
// Number of updates sent to UpdateableLogsConfig by LogsConfigManager
STAT_DEFINE(logsconfig_manager_published_update, SUM)
// LogsConfig manager receiving updates from the state machine
STAT_DEFINE(logsconfig_manager_received_update, SUM)
// The version of the last processed delta/snapshot on this node
STAT_DEFINE(logsconfig_manager_tree_version, MAX)
// LogsConfig Manager Is Started
STAT_DEFINE(logsconfig_manager_started, MAX)
// LogsConfig Manager deserialization errors
STAT_DEFINE(logsconfig_manager_serialization_errors, SUM)
// LogsConfig number of deltas applied
STAT_DEFINE(logsconfig_manager_delta_applied, SUM)

// BufferedWriter stats
STAT_DEFINE(buffered_writer_bytes_in, SUM)
STAT_DEFINE(buffered_writer_bytes_batched, SUM)
STAT_DEFINE(buffered_writer_manual_flush, SUM)
STAT_DEFINE(buffered_writer_max_payload_flush, SUM)
STAT_DEFINE(buffered_writer_time_trigger_flush, SUM)
STAT_DEFINE(buffered_writer_size_trigger_flush, SUM)

// No. of times a recipient got a Message payload where the checksum
// in the ProtocolHeader does not match the checksum computed on the recipient
STAT_DEFINE(protocol_checksum_mismatch, SUM)

// No. of times a recipient got a Message payload with a checksum
// in the ProtocolHeader and it matched the checksum computed on the recipient
STAT_DEFINE(protocol_checksum_matched, SUM)

// GetSeqStateRequest stats
// Number of times a GetSeqStateRequest was created.
// This doesn't count the retries or the reuse of the same request id.
STAT_DEFINE(get_seq_state_unique, SUM)

// Total number of times GetSeqStateRequests were merged.
STAT_DEFINE(get_seq_state_merged_total, SUM)

// Number of times a new GetSeqStateRequest was
// merged into an existing one because the options
// matched b/w both requests.
STAT_DEFINE(get_seq_state_merge_into_existing, SUM)

// Number of times an existing request's options
// matched with the new request, but the new request
// wants to start a new state machine instead of using
// the existing state machine, e.g. rebuilding
STAT_DEFINE(get_seq_state_merge_into_new, SUM)

// Number of times a GetSeqStateRequest was resent
// because sequencer sent E::AGAIN.
STAT_DEFINE(get_seq_state_resent, SUM)

// Number of times a GetSeqStateRequest timedout
STAT_DEFINE(get_seq_state_timedout, SUM)

// Total number of attempts that were made to issue GetSeqStateRequest.
// This includes the requests which may not be sent out
// because there already was an outstanding request.
STAT_DEFINE(get_seq_state_attempts_context_unknown, SUM)
STAT_DEFINE(get_seq_state_attempts_context_catchup_queue, SUM)
STAT_DEFINE(get_seq_state_attempts_context_findkey_message, SUM)
STAT_DEFINE(get_seq_state_attempts_context_islogempty_message, SUM)
STAT_DEFINE(get_seq_state_attempts_context_rebuilding_thread, SUM)
STAT_DEFINE(get_seq_state_attempts_context_rocksdb_cf, SUM)
STAT_DEFINE(get_seq_state_attempts_context_start_message, SUM)
STAT_DEFINE(get_seq_state_attempts_context_store_message, SUM)
STAT_DEFINE(get_seq_state_attempts_context_gettrimpoint_message, SUM)
STAT_DEFINE(get_seq_state_attempts_context_get_tail_lsn, SUM)
STAT_DEFINE(get_seq_state_attempts_context_rebuilding_seq_activator, SUM)
STAT_DEFINE(get_seq_state_attempts_context_sync_sequencer, SUM)
STAT_DEFINE(get_seq_state_attempts_context_get_tail_attributes, SUM)
STAT_DEFINE(get_seq_state_attempts_context_unreleased_record, SUM)
STAT_DEFINE(get_seq_state_attempts_context_metadata_util, SUM)
STAT_DEFINE(get_seq_state_attempts_context_historical_metadata, SUM)
STAT_DEFINE(get_seq_state_attempts_context_get_tail_record, SUM)

// No. of actual GetSeqStateRequests that were sent out
STAT_DEFINE(get_seq_state_unique_context_unknown, SUM)
STAT_DEFINE(get_seq_state_unique_context_catchup_queue, SUM)
STAT_DEFINE(get_seq_state_unique_context_findkey_message, SUM)
STAT_DEFINE(get_seq_state_unique_context_islogempty_message, SUM)
STAT_DEFINE(get_seq_state_unique_context_rebuilding_thread, SUM)
STAT_DEFINE(get_seq_state_unique_context_rocksdb_cf, SUM)
STAT_DEFINE(get_seq_state_unique_context_start_message, SUM)
STAT_DEFINE(get_seq_state_unique_context_store_message, SUM)
STAT_DEFINE(get_seq_state_unique_context_gettrimpoint_message, SUM)
STAT_DEFINE(get_seq_state_unique_context_get_tail_lsn, SUM)
STAT_DEFINE(get_seq_state_unique_context_rebuilding_seq_activator, SUM)
STAT_DEFINE(get_seq_state_unique_context_sync_sequencer, SUM)
STAT_DEFINE(get_seq_state_unique_context_get_tail_attributes, SUM)
STAT_DEFINE(get_seq_state_unique_context_unreleased_record, SUM)
STAT_DEFINE(get_seq_state_unique_context_metadata_util, SUM)
STAT_DEFINE(get_seq_state_unique_context_historical_metadata, SUM)
STAT_DEFINE(get_seq_state_unique_context_get_tail_record, SUM)

#undef STAT_DEFINE
