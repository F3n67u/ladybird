/*
 * Copyright (c) 2025, Feng Yu <f3n67u@outlook.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/ARIA/Roles.h>
#include <LibWeb/HTML/HTMLElement.h>

namespace Web::HTML {

class HTMLSelectedContentElement final : public HTMLElement {
    WEB_PLATFORM_OBJECT(HTMLSelectedContentElement, HTMLElement);
    GC_DECLARE_ALLOCATOR(HTMLSelectedContentElement);

public:
    virtual ~HTMLSelectedContentElement() override;

    // https://www.w3.org/TR/html-aria/#el-selectedcontent
    virtual Optional<ARIA::Role> default_role() const override { return ARIA::Role::generic; }

private:
    HTMLSelectedContentElement(DOM::Document&, DOM::QualifiedName);

    virtual void initialize(JS::Realm&) override;
};

}
