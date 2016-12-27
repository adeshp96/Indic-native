cmake_minimum_required(VERSION 2.8)
project(Indic_native)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/suggest/core/dicnode/internal/dic_node_properties.h
        src/suggest/core/dicnode/internal/dic_node_state.h
        src/suggest/core/dicnode/internal/dic_node_state_input.h
        src/suggest/core/dicnode/internal/dic_node_state_output.h
        src/suggest/core/dicnode/internal/dic_node_state_scoring.h
        src/suggest/core/dicnode/dic_node.cpp
        src/suggest/core/dicnode/dic_node.h
        src/suggest/core/dicnode/dic_node_pool.h
        src/suggest/core/dicnode/dic_node_priority_queue.h
        src/suggest/core/dicnode/dic_node_profiler.h
        src/suggest/core/dicnode/dic_node_utils.cpp
        src/suggest/core/dicnode/dic_node_utils.h
        src/suggest/core/dicnode/dic_node_vector.h
        src/suggest/core/dicnode/dic_nodes_cache.cpp
        src/suggest/core/dicnode/dic_nodes_cache.h
        src/suggest/core/dictionary/property/bigram_property.h
        src/suggest/core/dictionary/property/unigram_property.h
#        wrapper/transformed_core/suggest/core/dictionary/property/word_property.cpp
#        wrapper/transformed_core/suggest/core/dictionary/property/word_property.h
        src/suggest/core/dictionary/binary_dictionary_bigrams_iterator.h
        src/suggest/core/dictionary/binary_dictionary_shortcut_iterator.h
        src/suggest/core/dictionary/bloom_filter.h
        src/suggest/core/dictionary/dictionary.cpp
        src/suggest/core/dictionary/dictionary.h
        src/suggest/core/dictionary/dictionary_utils.cpp
        src/suggest/core/dictionary/dictionary_utils.h
        src/suggest/core/dictionary/digraph_utils.cpp
        src/suggest/core/dictionary/digraph_utils.h
        src/suggest/core/dictionary/error_type_utils.cpp
        src/suggest/core/dictionary/error_type_utils.h
        src/suggest/core/dictionary/multi_bigram_map.cpp
        src/suggest/core/dictionary/multi_bigram_map.h
        src/suggest/core/dictionary/ngram_listener.h
        src/suggest/core/layout/additional_proximity_chars.cpp
        src/suggest/core/layout/additional_proximity_chars.h
        src/suggest/core/layout/geometry_utils.h
        src/suggest/core/layout/normal_distribution.h
        src/suggest/core/layout/normal_distribution_2d.h
        src/suggest/core/layout/proximity_info.cpp
        src/suggest/core/layout/proximity_info.h
        src/suggest/core/layout/proximity_info_params.cpp
        src/suggest/core/layout/proximity_info_params.h
        src/suggest/core/layout/proximity_info_state.cpp
        src/suggest/core/layout/proximity_info_state.h
        src/suggest/core/layout/proximity_info_state_utils.cpp
        src/suggest/core/layout/proximity_info_state_utils.h
        src/suggest/core/layout/proximity_info_utils.h
        src/suggest/core/layout/touch_position_correction_utils.h
        src/suggest/core/policy/dictionary_bigrams_structure_policy.h
        src/suggest/core/policy/dictionary_header_structure_policy.h
        src/suggest/core/policy/dictionary_shortcuts_structure_policy.h
        src/suggest/core/policy/dictionary_structure_with_buffer_policy.h
        src/suggest/core/policy/scoring.h
        src/suggest/core/policy/suggest_policy.h
        src/suggest/core/policy/traversal.h
        src/suggest/core/policy/weighting.cpp
        src/suggest/core/policy/weighting.h
        src/suggest/core/result/suggested_word.h
        src/suggest/core/result/suggestion_results.cpp
        src/suggest/core/result/suggestion_results.h
        src/suggest/core/result/suggestions_output_utils.cpp
        src/suggest/core/result/suggestions_output_utils.h
        src/suggest/core/session/dic_traverse_session.cpp
        src/suggest/core/session/dic_traverse_session.h
        src/suggest/core/session/prev_words_info.h
        src/suggest/core/suggest.cpp
        src/suggest/core/suggest.h
        src/suggest/core/suggest_interface.h
        src/suggest/core/suggest_options.h
#        src/suggest/policyimpl/dictionary/header/header_policy.cpp
#        src/suggest/policyimpl/dictionary/header/header_policy.h
#        src/suggest/policyimpl/dictionary/header/header_read_write_utils.cpp
#        src/suggest/policyimpl/dictionary/header/header_read_write_utils.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/bigram/ver4_bigram_list_policy.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/bigram/ver4_bigram_list_policy.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/bigram_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/bigram_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/bigram_entry.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/dict_content.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/probability_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/probability_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/probability_entry.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/shortcut_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/shortcut_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/single_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/sparse_table_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/sparse_table_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/terminal_position_lookup_table.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/content/terminal_position_lookup_table.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/shortcut/ver4_shortcut_list_policy.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_dict_buffers.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_dict_buffers.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_dict_constants.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_dict_constants.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_node_reader.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_node_reader.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_node_writer.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_node_writer.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_policy.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_policy.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_reading_utils.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_reading_utils.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_writing_helper.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_patricia_trie_writing_helper.h
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_pt_node_array_reader.cpp
#        src/suggest/policyimpl/dictionary/structure/backward/v402/ver4_pt_node_array_reader.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/bigram/bigram_list_read_write_utils.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/bigram/bigram_list_read_write_utils.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/shortcut/shortcut_list_reading_utils.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/shortcut/shortcut_list_reading_utils.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_gc_event_listeners.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_gc_event_listeners.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_reading_helper.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_reading_helper.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_reading_utils.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_reading_utils.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_updating_helper.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_updating_helper.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_writing_utils.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/dynamic_pt_writing_utils.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/patricia_trie_reading_utils.cpp
#        src/suggest/policyimpl/dictionary/structure/pt_common/patricia_trie_reading_utils.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/pt_node_array_reader.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/pt_node_params.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/pt_node_reader.h
#        src/suggest/policyimpl/dictionary/structure/pt_common/pt_node_writer.h
#        src/suggest/policyimpl/dictionary/structure/v2/bigram/bigram_list_policy.h
#        src/suggest/policyimpl/dictionary/structure/v2/shortcut/shortcut_list_policy.h
#        src/suggest/policyimpl/dictionary/structure/v2/patricia_trie_policy.cpp
#        src/suggest/policyimpl/dictionary/structure/v2/patricia_trie_policy.h
#        src/suggest/policyimpl/dictionary/structure/v2/ver2_patricia_trie_node_reader.cpp
#        src/suggest/policyimpl/dictionary/structure/v2/ver2_patricia_trie_node_reader.h
#        src/suggest/policyimpl/dictionary/structure/v2/ver2_pt_node_array_reader.cpp
#        src/suggest/policyimpl/dictionary/structure/v2/ver2_pt_node_array_reader.h
#        src/suggest/policyimpl/dictionary/structure/v4/bigram/ver4_bigram_list_policy.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/bigram/ver4_bigram_list_policy.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/bigram_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/content/bigram_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/bigram_entry.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/language_model_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/content/language_model_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/probability_entry.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/shortcut_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/content/shortcut_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/single_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/sparse_table_dict_content.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/content/sparse_table_dict_content.h
#        src/suggest/policyimpl/dictionary/structure/v4/content/terminal_position_lookup_table.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/content/terminal_position_lookup_table.h
#        src/suggest/policyimpl/dictionary/structure/v4/shortcut/ver4_shortcut_list_policy.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_dict_buffers.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_dict_buffers.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_dict_constants.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_dict_constants.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_node_reader.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_node_reader.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_node_writer.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_node_writer.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_policy.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_policy.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_reading_utils.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_reading_utils.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_writing_helper.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_patricia_trie_writing_helper.h
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_pt_node_array_reader.cpp
#        src/suggest/policyimpl/dictionary/structure/v4/ver4_pt_node_array_reader.h
#        src/suggest/policyimpl/dictionary/structure/dictionary_structure_with_buffer_policy_factory.cpp
#        src/suggest/policyimpl/dictionary/structure/dictionary_structure_with_buffer_policy_factory.h
#        src/suggest/policyimpl/dictionary/utils/buffer_with_extendable_buffer.cpp
#        src/suggest/policyimpl/dictionary/utils/buffer_with_extendable_buffer.h
#        src/suggest/policyimpl/dictionary/utils/byte_array_utils.cpp
#        src/suggest/policyimpl/dictionary/utils/byte_array_utils.h
#        src/suggest/policyimpl/dictionary/utils/dict_file_writing_utils.cpp
#        src/suggest/policyimpl/dictionary/utils/dict_file_writing_utils.h
#        src/suggest/policyimpl/dictionary/utils/file_utils.cpp
#        src/suggest/policyimpl/dictionary/utils/file_utils.h
#        src/suggest/policyimpl/dictionary/utils/forgetting_curve_utils.cpp
#        src/suggest/policyimpl/dictionary/utils/forgetting_curve_utils.h
#        src/suggest/policyimpl/dictionary/utils/format_utils.cpp
#        src/suggest/policyimpl/dictionary/utils/format_utils.h
#        src/suggest/policyimpl/dictionary/utils/historical_info.h
#        src/suggest/policyimpl/dictionary/utils/mmapped_buffer.cpp
#        src/suggest/policyimpl/dictionary/utils/mmapped_buffer.h
#        src/suggest/policyimpl/dictionary/utils/probability_utils.h
#        src/suggest/policyimpl/dictionary/utils/sparse_table.cpp
#        src/suggest/policyimpl/dictionary/utils/sparse_table.h
#        src/suggest/policyimpl/dictionary/utils/trie_map.cpp
#        src/suggest/policyimpl/dictionary/utils/trie_map.h
        src/suggest/policyimpl/gesture/gesture_suggest_policy_factory.cpp
        src/suggest/policyimpl/gesture/gesture_suggest_policy_factory.h
        src/suggest/policyimpl/typing/scoring_params.cpp
        src/suggest/policyimpl/typing/scoring_params.h
        src/suggest/policyimpl/typing/typing_scoring.cpp
        src/suggest/policyimpl/typing/typing_scoring.h
        src/suggest/policyimpl/typing/typing_suggest_policy.cpp
        src/suggest/policyimpl/typing/typing_suggest_policy.h
        src/suggest/policyimpl/typing/typing_suggest_policy_factory.h
        src/suggest/policyimpl/typing/typing_traversal.cpp
        src/suggest/policyimpl/typing/typing_traversal.h
        src/suggest/policyimpl/typing/typing_weighting.cpp
        src/suggest/policyimpl/typing/typing_weighting.h
        src/suggest/policyimpl/utils/damerau_levenshtein_edit_distance_policy.h
        src/suggest/policyimpl/utils/edit_distance.h
        src/suggest/policyimpl/utils/edit_distance_policy.h
        src/utils/autocorrection_threshold_utils.cpp
        src/utils/autocorrection_threshold_utils.h
        src/utils/byte_array_view.h
        src/utils/char_utils.cpp
        src/utils/char_utils.h
        src/utils/int_array_view.h
#        wrapper/transformed_core/utils/jni_data_utils.cpp
#        wrapper/transformed_core/utils/jni_data_utils.h
#        wrapper/transformed_core/utils/log_utils.cpp
#        wrapper/transformed_core/utils/log_utils.h
        src/utils/time_keeper.cpp
        src/utils/time_keeper.h
        src/defines.h)

include_directories(src)
include_directories(src/suggest/core)
include_directories(src/suggest/core/dicnode)
include_directories(src/suggest/core/dicnode/internal)
include_directories(src/suggest/core/dictionary)
include_directories(src/suggest/core/dictionary/property)
include_directories(src/suggest/core/layout)
include_directories(src/suggest/core/policy)
include_directories(src/suggest/core/result)
include_directories(src/suggest/core/session)
#include_directories(src/suggest/policyimpl/dictionary/header)
#include_directories(src/suggest/policyimpl/dictionary/structure)
#include_directories(src/suggest/policyimpl/dictionary/structure/backward/v402)
#include_directories(src/suggest/policyimpl/dictionary/structure/backward/v402/bigram)
#include_directories(src/suggest/policyimpl/dictionary/structure/backward/v402/content)
#include_directories(src/suggest/policyimpl/dictionary/structure/backward/v402/shortcut)
#include_directories(src/suggest/policyimpl/dictionary/structure/pt_common)
#include_directories(src/suggest/policyimpl/dictionary/structure/pt_common/bigram)
#include_directories(src/suggest/policyimpl/dictionary/structure/pt_common/shortcut)
#include_directories(src/suggest/policyimpl/dictionary/structure/v2)
#include_directories(src/suggest/policyimpl/dictionary/structure/v2/bigram)
#include_directories(src/suggest/policyimpl/dictionary/structure/v2/shortcut)
#include_directories(src/suggest/policyimpl/dictionary/structure/v4)
#include_directories(src/suggest/policyimpl/dictionary/structure/v4/bigram)
#include_directories(src/suggest/policyimpl/dictionary/structure/v4/content)
#include_directories(src/suggest/policyimpl/dictionary/structure/v4/shortcut)
#include_directories(src/suggest/policyimpl/dictionary/utils)
include_directories(src/suggest/policyimpl/gesture)
include_directories(src/suggest/policyimpl/typing)
#include_directories(src/suggest/policyimpl/utils)
include_directories(src/utils)

add_executable(Indic_native ${SOURCE_FILES})