// Marco Ivaldi <raptor@0xdeadbeef.info>

void bt_mesh_beacon_priv_random_get(uint8_t *random, size_t size)
{
	// ruleid: raptor-suspicious-assert
	__ASSERT(size <= sizeof(priv_random.val), "Invalid random value size %u", size);
	memcpy(random, priv_random.val, size);
}

static inline int send_sf(struct isotp_send_ctx *ctx)
{
	/* ... */
	if (ctx->tx_addr.use_ext_addr)
	{
		frame.data[index++] = ctx->tx_addr.ext_addr;
	}

	frame.data[index++] = ISOTP_PCI_TYPE_SF | len;

	// ruleid: raptor-suspicious-assert
	__ASSERT_NO_MSG(len <= ISOTP_CAN_DL - index);
	memcpy(&frame.data[index], data, len);

	/* ... */

	return 0;
}

static inline void assert_buf_len(int need, int have)
{
	// ruleid: raptor-suspicious-assert
	__ASSERT(need < have, "OOM at build command: need:%d have:%d",
			 need, have);
}

static int line_out_drop_mode(void)
{
	/* line cannot be empty */
	// ruleid: raptor-suspicious-assert
	__ASSERT_NO_MSG(line_pos > line_buf);

	/* Handle the case if line contains only '\n' */
	if (line_pos - line_buf == 1)
	{
		line_pos++;
	}

	*(line_pos - 1) = '\r';
	*line_pos++ = '\n';

	if (drop_cnt > 0 && !drop_warn)
	{
		int cnt = MIN(drop_cnt, DROP_MAX);

		// ruleid: raptor-suspicious-assert
		__ASSERT_NO_MSG(line_pos - line_buf <= MESSAGE_SIZE);

		memmove(line_buf + DROP_MSG_LEN, line_buf, line_pos - line_buf);
		(void)memcpy(line_buf, drop_msg, DROP_MSG_LEN);
		line_pos += DROP_MSG_LEN;
		drop_warn = 1;

		/* ... */
	}
	return 0;
}

void arch_irq_offload(irq_offload_routine_t routine, const void *parameter)
{
	offload_params[CURR_CPU].fn = routine;
	offload_params[CURR_CPU].arg = parameter;
	compiler_barrier();

	z_arc_v2_aux_reg_write(_ARC_V2_AUX_IRQ_HINT, IRQ_OFFLOAD_LINE);

	/* ... */

	/* If _current was aborted in the offload routine, we shouldn't be here */
	// ok: raptor-suspicious-assert
	__ASSERT_NO_MSG((_current->base.thread_state & _THREAD_DEAD) == 0);
}

int process_sub(FILE *data_file, FILE *struct_file)
{
	FIND_T fInfo;
	FIND_RET_T fret;
	int filesProcessed = 0;

	if (processSubs)
	{
		/* process subs recursively */
		size_t sublen = strlen(curSubdir);
		size_t freelen = sizeof(curSubdir) - sublen - 1;
		// ruleid: raptor-suspicious-assert
		LWIP_ASSERT("sublen < sizeof(curSubdir)", sublen < sizeof(curSubdir));
		fret = FINDFIRST_DIR("*", &fInfo);
		/* ... */
	}

	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
