/*
 * Copyright (c) 2021, Brandon Scott <xeon.productions@gmail.com>
 * Copyright (c) 2020, Hunter Salyer <thefalsehonesty@gmail.com>
 * Copyright (c) 2021-2022, Sam Atkins <atkinssj@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Vector.h>
#include <LibJS/Console.h>
#include <LibJS/Forward.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Forward.h>
#include <WebContent/Forward.h>

namespace WebContent {

class WebContentConsoleClient : public JS::ConsoleClient {
    GC_CELL(WebContentConsoleClient, JS::ConsoleClient);
    GC_DECLARE_ALLOCATOR(WebContentConsoleClient);

public:
    virtual ~WebContentConsoleClient() override;

    void handle_input(StringView js_source);

    virtual void handle_result(JS::Value) = 0;
    virtual void send_messages(i32 start_index) = 0;

protected:
    WebContentConsoleClient(JS::Realm&, JS::Console&, PageClient&, ConsoleGlobalEnvironmentExtensions&);

    virtual void visit_edges(JS::Cell::Visitor&) override;

    void print_html(String const& line);

    virtual void clear() override;
    void clear_output();

    void begin_group(String const& label, bool start_expanded);
    virtual void end_group() override;

    GC::Ref<JS::Realm> m_realm;
    GC::Ref<PageClient> m_client;
    GC::Ref<ConsoleGlobalEnvironmentExtensions> m_console_global_environment_extensions;

    struct ConsoleOutput {
        enum class Type {
            HTML,
            Clear,
            BeginGroup,
            BeginGroupCollapsed,
            EndGroup,
        };
        Type type;
        String data;
    };
    Vector<ConsoleOutput> m_message_log;
};

}
