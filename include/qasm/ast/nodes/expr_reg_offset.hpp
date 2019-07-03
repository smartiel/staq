/*-------------------------------------------------------------------------------------------------
| This file is distributed under the MIT License.
| See accompanying file /LICENSE for details.
| Author(s): Bruno Schmitt
| Forked from boschmitt/synthewareQ
*------------------------------------------------------------------------------------------------*/
#pragma once

#include "../ast_context.hpp"
#include "../ast_node.hpp"
#include "../ast_node_kinds.hpp"

#include <memory>
#include <string>

namespace synthewareQ {
namespace qasm {

  class expr_reg_offset
    : public ast_node
    , public ast_node_container<expr_reg_offset, ast_node> {
  public:

    static expr_reg_offset* build(ast_context* ctx, uint32_t location, std::string_view id, ast_node* expr)
    {
      return new (*ctx) expr_reg_offset(location, id, expr);
    }

    std::string_view id() const
    {
      return id_;
    }

    ast_node& index()
    {
      return *(this->begin());
    }

    /*
    std::optional<uint32_t> index_numeric() const
    {
      return *(this->begin());
    }
    */


  private:
    expr_reg_offset(uint32_t location, std::string_view id, ast_node* expr)
      : ast_node(location)
      , id_(id)
    { add_child(expr); }

    ast_node_kinds do_get_kind() const override
	{
      return ast_node_kinds::expr_reg_offset;
	}

  private:
    std::string id_;
  };

} // namespace qasm
} // namespace synthewareQ